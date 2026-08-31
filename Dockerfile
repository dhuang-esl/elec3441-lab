FROM ubuntu:24.04 AS ripes-builder

ARG DEBIAN_FRONTEND=noninteractive
ARG RIPES_COMMIT=976190de359dd683a3e90c74ffa371c39780308d

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    ca-certificates \
    cmake \
    git \
    libegl1-mesa-dev \
    libqt5charts5-dev \
    libqt5svg5-dev \
    qtbase5-dev \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /tmp/ripes \
    && git -C /tmp/ripes init \
    && git -C /tmp/ripes remote add origin https://github.com/mortbopet/Ripes.git \
    && git -C /tmp/ripes fetch --depth 1 origin "${RIPES_COMMIT}" \
    && git -C /tmp/ripes checkout --detach FETCH_HEAD \
    && git -C /tmp/ripes submodule update --init --recursive --depth 1 \
    && sed -i '/#include <map>/a #include <cstdint>' /tmp/ripes/external/VSRTL/interface/vsrtl_vcdfile.h \
    && cmake -S /tmp/ripes -B /tmp/ripes/build \
      -DCMAKE_BUILD_TYPE=Release \
      -DCMAKE_INSTALL_PREFIX=/opt/ripes \
    && cmake --build /tmp/ripes/build --parallel 2 \
    && cmake --install /tmp/ripes/build

FROM ubuntu:24.04 AS riscv-toolchain

ARG DEBIAN_FRONTEND=noninteractive
ARG RISCV_TOOLCHAIN_VERSION=13.2.0-2
ARG RISCV_TOOLCHAIN_ARM64_SHA256=1c981c611a38dfe5af902089aed570d4dd501eb4ed88d801043e59ab9a62a86a
ARG RISCV_TOOLCHAIN_AMD64_SHA256=52545afb900200fbf65fe05f7ce7090b8a42c64091f4f5d43cae6bb68ea2434a

RUN apt-get update && apt-get install -y --no-install-recommends \
    ca-certificates \
    curl \
    && rm -rf /var/lib/apt/lists/*

RUN target_arch=$(dpkg --print-architecture) \
    && case "${target_arch}" in \
      arm64) archive="xpack-riscv-none-elf-gcc-${RISCV_TOOLCHAIN_VERSION}-linux-arm64.tar.gz"; sha="${RISCV_TOOLCHAIN_ARM64_SHA256}" ;; \
      amd64) archive="xpack-riscv-none-elf-gcc-${RISCV_TOOLCHAIN_VERSION}-linux-x64.tar.gz"; sha="${RISCV_TOOLCHAIN_AMD64_SHA256}" ;; \
      *) echo "Unsupported Docker architecture: ${target_arch}" >&2; exit 1 ;; \
    esac \
    && curl -fL "https://github.com/xpack-dev-tools/riscv-none-elf-gcc-xpack/releases/download/v${RISCV_TOOLCHAIN_VERSION}/${archive}" -o "/tmp/${archive}" \
    && echo "${sha}  /tmp/${archive}" | sha256sum -c - \
    && mkdir -p /opt/riscv \
    && tar -xzf "/tmp/${archive}" --strip-components=1 -C /opt/riscv \
    && rm -f "/tmp/${archive}" \
    && /opt/riscv/bin/riscv-none-elf-gcc --version

FROM ubuntu:24.04 AS spike-builder

ARG DEBIAN_FRONTEND=noninteractive
ARG SPIKE_COMMIT=530af85d83781a3dae31a4ace84a573ec255fefa

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    ca-certificates \
    device-tree-compiler \
    git \
    libboost-regex-dev \
    libboost-system-dev \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /tmp/spike \
    && git -C /tmp/spike init \
    && git -C /tmp/spike remote add origin https://github.com/riscv-software-src/riscv-isa-sim.git \
    && git -C /tmp/spike fetch --depth 1 origin "${SPIKE_COMMIT}" \
    && git -C /tmp/spike checkout --detach FETCH_HEAD \
    && git -C /tmp/spike submodule update --init --recursive --depth 1 \
    && sed -i '/#include <vector>/i #include <cstdint>' /tmp/spike/fesvr/device.h \
    && mkdir -p /tmp/spike/build \
    && cd /tmp/spike/build \
    && ../configure --prefix=/opt/spike \
    && make -j4 \
    && make install

FROM ubuntu:24.04 AS pk-builder

ARG DEBIAN_FRONTEND=noninteractive
ARG PK_COMMIT=4ae5a8876fc2c31776b1777405ab14f764cc0f36

RUN apt-get update && apt-get install -y --no-install-recommends \
    autoconf \
    automake \
    build-essential \
    ca-certificates \
    git \
    && rm -rf /var/lib/apt/lists/*

COPY --from=riscv-toolchain /opt/riscv /opt/riscv

ENV PATH=/opt/riscv/bin:${PATH}

RUN for source in /opt/riscv/bin/riscv-none-elf-*; do \
      tool=$(basename "${source}" | sed 's/^riscv-none-elf-//'); \
      ln -s "${source}" "/usr/local/bin/riscv32-unknown-elf-${tool}"; \
    done \
    && mkdir -p /tmp/pk \
    && git -C /tmp/pk init \
    && git -C /tmp/pk remote add origin https://github.com/riscv-software-src/riscv-pk.git \
    && git -C /tmp/pk fetch --depth 1 origin "${PK_COMMIT}" \
    && git -C /tmp/pk checkout --detach FETCH_HEAD \
    && mkdir -p /tmp/pk/build \
    && cd /tmp/pk/build \
    && ../configure \
      --prefix=/opt/pk \
      --host=riscv32-unknown-elf \
      --with-arch=rv32i_zicsr_zifencei \
      --with-abi=ilp32 \
    && make -j4 \
    && make install \
    && test -x /opt/pk/riscv32-unknown-elf/bin/pk

FROM ubuntu:24.04

ARG DEBIAN_FRONTEND=noninteractive
ARG RARS_VERSION=1.6
ARG RARS_SHA256=780f730eb457b1ba609e968accc2c8b77d8f92c3d9dbf30cc7fdb3cfb14e8c24
ARG LOGISIM_VERSION=4.1.0
ARG LOGISIM_SHA256=fe6386a3217a591bcc311a4eda49e1f43a389b499dd3d0f6f40f344fc85f2577

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    ca-certificates \
    curl \
    dbus-x11 \
    device-tree-compiler \
    fluxbox \
    libfontconfig1 \
    libgl1 \
    libglib2.0-0 \
    libboost-regex-dev \
    libboost-system-dev \
    libncurses6 \
    libqt5charts5 \
    libqt5svg5 \
    libxkbcommon-x11-0 \
    novnc \
    openjdk-21-jre \
    python3-matplotlib \
    python3-tk \
    sudo \
    unzip \
    websockify \
    x11vnc \
    xauth \
    xterm \
    xvfb \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /opt/rars /opt/logisim \
    && curl -fL "https://github.com/TheThirdOne/rars/releases/download/v${RARS_VERSION}/rars1_6.jar" -o /opt/rars/rars.jar \
    && echo "${RARS_SHA256}  /opt/rars/rars.jar" | sha256sum -c - \
    && curl -fL "https://github.com/logisim-evolution/logisim-evolution/releases/download/v${LOGISIM_VERSION}/logisim-evolution-${LOGISIM_VERSION}-all.jar" -o /opt/logisim/logisim.jar \
    && echo "${LOGISIM_SHA256}  /opt/logisim/logisim.jar" | sha256sum -c -

COPY --from=ripes-builder /opt/ripes /opt/ripes
COPY --from=riscv-toolchain /opt/riscv /opt/riscv
COPY --from=spike-builder /opt/spike /opt/spike
COPY --from=pk-builder /opt/pk /opt/pk

COPY container/tool /usr/local/bin/elec3441-tool
COPY container/start-gui /usr/local/bin/start-gui
COPY container/prepare-workspace /usr/local/bin/prepare-workspace
COPY container/verify-setup /usr/local/bin/verify-setup
COPY student-materials /opt/elec3441/student-materials

RUN chmod 755 /usr/local/bin/elec3441-tool /usr/local/bin/start-gui /usr/local/bin/prepare-workspace /usr/local/bin/verify-setup \
    && chmod -R a+rX /opt/elec3441/student-materials \
    && for tool in rars logisim ripes spike riscv32-unknown-elf-gcc riscv32-unknown-elf-g++ riscv32-unknown-elf-objdump riscv32-unknown-elf-objcopy riscv32-unknown-elf-ld riscv32-unknown-elf-as riscv32-unknown-elf-gas; do \
      ln -s /usr/local/bin/elec3441-tool "/usr/local/bin/${tool}"; \
    done \
    && ln -s /opt/pk/riscv32-unknown-elf/bin/pk /usr/local/bin/pk \
    && useradd --create-home --shell /bin/bash student \
    && usermod --append --groups sudo student \
    && printf 'student ALL=(ALL:ALL) NOPASSWD: ALL\n' > /etc/sudoers.d/student \
    && chmod 440 /etc/sudoers.d/student \
    && mkdir -p /workspace \
    && chown student:student /workspace

USER student
WORKDIR /workspace

ENV DISPLAY=:0 \
    LD_LIBRARY_PATH=/opt/spike/lib \
    PATH=/usr/local/bin:/opt/riscv/bin:/opt/spike/bin:${PATH}
EXPOSE 6080

ENTRYPOINT ["/usr/local/bin/start-gui"]
