CC=g++
CFLAGS=-I $(BOOST_ROOT) -pthread

release: main.cpp
	$(CC) -o http main.cpp $(CFLAGS)

clean:
	rm http