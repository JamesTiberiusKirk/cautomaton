all: cautomaton

cautomaton:
	gcc -Wall -Werror -o $@ main.c

clean:
	rm -rf cautomaton


