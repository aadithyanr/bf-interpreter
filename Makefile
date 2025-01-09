CC=gcc
CFLAGS=-Wall -Wextra -g
TARGET=brainfuck
SRC=brainfuck.c
all:$(TARGET)
$(TARGET):$(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)
clean:
	rm -f $(TARGET)