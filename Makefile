CC=gcc
CFLAGS=-O0 -Werror -pedantic

projekt:
	 $(CC) $(CFLAGS) gradient_descent.c  -o projekt -lm

clean:
	rm projekt
