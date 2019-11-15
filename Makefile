CC=gcc
CFLAGS=-O0 -g2 -Werror -pedantic -lm -std=c99



gradient_descent:
	 $(CC) gradient_descent.c -o gradient_descent $(CFLAGS)

clean:
	rm -rf gradient_descent *.o

all:    gradient_descent
