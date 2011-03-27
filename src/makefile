CC=g++

CFLAGS=-c -Wall -O3

all: mimic

mimic: main.o print.o gen.o read.o test.o strfunc.o
	$(CC) main.o print.o gen.o read.o test.o strfunc.o -o mimic

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

print.o: print.cpp
	$(CC) $(CFLAGS) print.cpp

gen.o: gen.cpp
	$(CC) $(CFLAGS) gen.cpp

read.o: read.cpp
	$(CC) $(CFLAGS) read.cpp

test.o: test.cpp
	$(CC) $(CFLAGS) test.cpp

strfunc.o: strfunc.cpp
	$(CC) $(CFLAGS) strfunc.cpp
clean: 
	rm -rf *o mimic
