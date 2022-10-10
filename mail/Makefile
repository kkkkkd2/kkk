CC=gcc
BIN=all
OBJ=main.o phone_book.o tools.o
STD=-std=gnu99
FLAG=-Wall -Werror
LD=-lm
INCLUDE=-I.

all:$(OBJ)
	$(CC) -o $(BIN) $(OBJ) $(LD)

%.o:%.c
	$(CC) $(STD) $(FLAG) -c $< -o $@

clean:
	rm -rf $(BIN) $(OBJ)
