CC=gcc
CFLAGS=-O0 --Werror -pedantic


projekt:
	 $(CC) -o projekt gradient_descent.c
