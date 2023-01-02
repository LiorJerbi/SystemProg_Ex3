CC = gcc
FLAGS = -Wall -g -fPIC

all: txtfind isort 

txtfind: txtfind.o
	$(CC) $(FLAGS) -o txtfind txtfind.o

txtfind.o: txtfind.c
	$(CC) $(FLAGS) -c txtfind.c

isort: isort.o
	$(CC) $(FLAGS) -o isort isort.o

isort.o: isort.c
	$(CC) $(FLAGS) -c isort.c

.PHONY: clean all

clean:
	rm -f *.o isort txtfind