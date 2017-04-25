//EDSON YUDI TOMA - 9791305
#ifndef FILA_H
#define FILA_H

typedef struct FILA FILA;

FILA *criarFila();
int vaziaFila(FILA *);
int add(FILA *, int);
int rem(FILA *);
void apagarFila(FILA *);

#endif
