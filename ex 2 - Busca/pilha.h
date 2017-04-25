//EDSON YUDI TOMA - 9791305
#ifndef PILHA_H
#define PILHA_H

typedef struct PILHA PILHA;

PILHA *criarPilha();
int vaziaPilha(PILHA *);
int push(PILHA *, int);
int pop(PILHA *);
void apagarPilha(PILHA *);

#endif
