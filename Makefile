.POSIX:
.SUFFIXES:
CC = gcc
CFLAGS = -std=c11 -g -Wall -Wextra
SRC = ./src

OBJECTS=$(SRC)/qs.o $(SRC)/token.o

all: qs

qs: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

clean:
	rm -fv qs
	rm -fv $(SRC)/*.o

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -c $<
