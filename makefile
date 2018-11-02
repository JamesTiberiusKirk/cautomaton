all: 2dcautomaton rule30 cautomatonv2

CC=gcc
CFLAGS= -Wall -Werror -g

2dcautomaton: 
	$(CC) $(CFLAGS) -o $@ 2dcautomaton.c

rule30:
	$(CC) $(CFLAGS) -o $@ rule30.c

cautomatonv2:
	$(CC) $(CFLAGS) -o $@ cautomatonv2.c


clean:
	rm -rf 2dcautomaton cautomatonv2 *.o rule30 *.gch 


