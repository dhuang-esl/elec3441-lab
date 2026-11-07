# Makefile to generate riscv binaries


CC=riscv32-unknown-elf-gcc
CXX=riscv32-unknown-elf-g++

benchmarks=\
	bfs_matrix \
	bfs_pointer \
	conv2D  \
	kmean   \
	mm      \
	sobel   \
	fir     \
	quicksort \

all :
	set -e; for d in $(benchmarks); do $(MAKE) -C $$d; done

run :
	set -e; for d in $(benchmarks); do (cd $$d && spike pk $$d); done

clean:
	set -e; for d in $(benchmarks); do $(MAKE) -C $$d clean; done
