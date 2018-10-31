all: cautomaton

CC=gcc
CFLAGS= -Wall -Werror -g

cautomaton: cautomaton.o
	$(CC) $(CFLAGS) -o $@ main.c cautomaton.o

cautomaton.o:
	$(CC) $(CFLAGS) -c cautomaton.c cautomaton.h 

rule30:
	$(CC) $(CFLAGS) -o $@ rule30.c

cautomatonv2:
	$(CC) $(CFLAGS) -o $@ cautomatonv2.c


clean:
	rm -rf cautomaton cautomatonv2 *.o rule30 *.gch 


