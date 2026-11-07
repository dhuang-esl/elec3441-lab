CC = riscv32-unknown-elf-gcc
#CFLAGS= -DDEBUG -g -Wall
CFLAGS= -g -O3 
TARGET = mm 
SRCS = mm_ip.c \
	   mm_main.c

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

.cpp.o:
	$(CC) -c $(CFLAGS) $< -o  $@

clean:
	rm -f $(OBJS) $(TARGET) core.*

depend:
	makedepend $(SRCS)

# DO NOT DELETE

