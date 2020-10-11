CC=g++
CFLAGS=-pthread -Werror -Wall -Wextra -O3

release: main.cpp
	$(CC) -o http main.cpp server.cpp connection.cpp $(CFLAGS)

clean:
	rm http