#!/bin/make

# CFLAGS=-Wno-format -Wno-deprecated-declarations -Wno-format-security -lm `pkg-config --cflags --libs gtk+-3.0` -export-dynamic
CFLAGS=-g -Wno-format -Wno-deprecated-declarations -Wno-format-security -lm 


all: libafile.so


libafile.so: libafile.c util.h
	gcc -o libafile.so -fpic -shared libafile.c $(CFLAGS)

clean:
	rm -rf *.o libafile.so

