all: clean pilha.o fila.o busca.o matriz.o main.o
	@gcc pilha.o fila.o matriz.o busca.o main.o -o main -Wall -std=c99

pilha.o:
	@gcc -c pilha.c -std=c99

fila.o:
	@gcc -c fila.c -std=c99

matriz.o:
	@gcc -c matriz.c -std=c99

busca.o:
	@gcc -c busca.c -std=c99

main.o:
	@gcc -c main.c -std=c99

run:
	@./main

clean:
	@find -name '*.o' | xargs rm -rf {}
	@find -name '*~' | xargs rm -rf {}

zip:
	zip -r main *.c *.h Makefile

