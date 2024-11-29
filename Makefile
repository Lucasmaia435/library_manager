all: funcs.o
	gcc -o funcs funcs.o main.c -o main

funcs.o: funcs.h definitions.h
	gcc -c funcs.c
