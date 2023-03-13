CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11

SRC = main.c brainfuck.c
OBJ = $(SRC:.c=.o)

all: build

build: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o brainfuck

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) brainfuck

run: build
	./brainfuck