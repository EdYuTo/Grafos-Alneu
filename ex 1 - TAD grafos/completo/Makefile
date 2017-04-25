all: clean matriz.o lista.o main.o
	@gcc matriz.o lista.o main.o -o main -Wall -std=c99

matriz.o:
	@gcc -c matriz.c

lista.o:
	@gcc -c lista.c

main.o:
	@gcc -c main.c

run:
	@./main

clean:
	@find -name '*.o' | xargs rm -rf {}
	@find -name '*~' | xargs rm -rf {}

zip:
	zip -r main *.c *.h Makefile

