CC=gcc
CFLAGS=-O0 -g2 -Werror -pedantic

projekt:
	 $(CC) $(CFLAGS) gradient_descent.c  -o projekt -lm -std=c99

clean:
	rm projekt
