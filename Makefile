#!/bin/make

# CFLAGS=-Wno-format -Wno-deprecated-declarations -Wno-format-security -lm `pkg-config --cflags --libs gtk+-3.0` -export-dynamic
# CFLAGS=-g -Wno-format -Wno-deprecated-declarations -Wno-format-security -lm 
CFLAGS=-g
CC=gcc 


all: libafile.so


libafile.so: libafile.c file.h
	$(CC) -o libafile.so -fpic -shared libafile.c $(CFLAGS)


test.o: test.c
	$(CC) -c test.c $(CFLAGS)

test2: test2.o 
	$(CC) test2.o -o test2 $(CFLAGS)


clean:
	rm -rf *.o libafile.so test
