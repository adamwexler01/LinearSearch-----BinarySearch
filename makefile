all: search

search: Search.o
	g++ Search.o -o search
Search.o: Search.cpp
	g++ -c Search.cpp
