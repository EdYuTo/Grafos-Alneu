all: clean matriz.o main.o
	@gcc matriz.o main.o -o main -Wall

matriz.o:
	@gcc -c matriz.c

main.o:
	@gcc -c main.c

run:
	@./main

clean:
	@find -name '*.o' | xargs rm -rf {}
	@find -name '*~' | xargs rm -rf {}

zip:
	zip -r main *.c *.h Makefile

