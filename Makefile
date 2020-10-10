CC=g++
CFLAGS=-I.

release: main.cpp
	$(CC) -o http main.cpp


clean:
	rm http