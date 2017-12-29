CC=gcc
CFLAGS=-O0 -g2 -Werror -pedantic -lm -std=c99


gradient_descent.o: gradient_descent.c gradient_descent.h
	 $(CC) gradient_descent.c -c -o gradient_descent.o  $(CFLAGS)

gradient_descent: gradient_descent.o 
	 $(CC) gradient_descent.o -o gradient_descent $(CFLAGS)

clean:
	rm -rf gradient_descent *.o


all:    gradient_descent
