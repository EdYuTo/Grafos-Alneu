all: clean lista.o main.o
	@gcc lista.o main.o -o main -Wall

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

