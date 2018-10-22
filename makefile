all: cautomaton

CC=gcc
CFLAGS= -Wall -Werror -g

cautomaton: cautomaton.o
	$(CC) $(CFLAGS) -o $@ main.c

cautomaton.o:
	$(CC) $(CFLAGS) -c cautomaton.c 

rule30:
	$(CC) $(CFLAGS) -o $@ rule30.c

clean:
	rm -rf cautomaton


