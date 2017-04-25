//EDSON YUDI TOMA - 9791305
#ifndef LISTA_H
#define LISTA_H

typedef struct NO {
   int valor;
   int col;
   struct NO *prox;
   struct NO *ant;
} NO;

typedef struct lista {
   int n; //numero de linhas/colunas
   NO **no;
} LISTA;

LISTA *criarL(int n);  //criar lista
void apagarL(LISTA *lista);  //apagar lista
void imprimirLi(LISTA *lista);  //imprimir lista
void imprimirRo(LISTA *lista, int n);  //imprimir uma linha (row) da lista
void imprimirTr(LISTA *lista);  //imprimir a transposta
void imprimirAr(LISTA *lista, int d);  //imprimir uma aresta
int setL(LISTA *lista, int lin, int col, int val);  //adicionar um valor na lista
int remL(LISTA *lista, int lin, int col);  //remove elemento

#endif
