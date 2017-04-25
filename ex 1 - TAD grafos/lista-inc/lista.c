#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX(a,b) a>=b ? a : b
#define MIN(a,b) a<=b ? a : b

LISTA *criarL(int n) {
   LISTA *lista = (LISTA *)malloc(sizeof(LISTA));
   if (lista != NULL) {
      lista->n = n;
      lista->no = (NO **)malloc(sizeof(NO *) * n);
      for (int i = 0; i < n; i++) {
         lista->no[i] = (NO *)malloc(sizeof(NO));
         lista->no[i]->valor = -1;  //-1 indica q se trata de um no cabeca
         lista->no[i]->col = 0;
         lista->no[i]->prox = NULL;
         lista->no[i]->ant = NULL;
      }
   }
   return lista;
}

void apagarL(LISTA *lista) {
   if (lista != NULL) {
      for (int i = 0; i < lista->n; i++) {
         NO *pant = lista->no[i];
         NO *prem = lista->no[i]->prox;
         while (prem != NULL) {
            free(pant);
            pant = prem;
            prem = prem->prox;
         }
         free(pant);
      }
      free(lista->no);
      free(lista);
   }
}

void imprimirLi(LISTA *lista) {  //imprimir matriz
   if (lista != NULL) {
      NO *aux;
      for (int i = 0; i < lista->n; i++) {  //imprime as linhas
         aux = lista->no[i];
         printf("%d. ", i);
         if (aux->valor > -1)  //caso o vertice seja adjacente a ele mesmo
            printf("%d(%d) ", aux->col, aux->valor);
         while (aux->prox != NULL) {  //imprime as colunas
            aux = aux->prox;
            printf("%d(%d) ", aux->col, aux->valor);
         }
         printf("\n");
      }
   }
}

void imprimirRo(LISTA *lista, int n) {  //imprimir uma linha (row) da matriz
   if (lista != NULL) {
      NO *aux = lista->no[n]; 
      if (aux->valor > -1)  //caso o vertice seja adjacente a ele mesmo
         printf("%d ", aux->col);
      while (aux->prox != NULL) {
         aux = aux->prox;
         printf("%d ", aux->col);
      }
      printf("\n");
   }
}

void imprimirAr(LISTA *lista, int d) {  //imprimir menor aresta
   if (lista != NULL) {
      int aux = -1, lin, col;
      for (int i = 0; i < lista->n; i++) {
         NO *no = lista->no[i];
         for (int j = 0; no != NULL; no = no->prox, j++)
            if (aux == -1 || (no->valor > -1 && no->valor < aux)) {
               aux = no->valor;
               lin = i;
               col = no->col;
            }
      }
      if (d)  //e digrafo
         printf("%d %d\n", lin, col);
      else {  //nao e digrafo
         printf("%d %d\n", MIN(lin,col), MAX(lin,col));
      }
   }
}

int setL(LISTA *lista, int lin, int col, int val) {  //adicionar um valor na matriz
   if (lista != NULL) {
      NO *aux = lista->no[lin];
      for (; aux->prox != NULL && aux->col < col; aux = aux->prox);
      if (aux->prox == NULL) {
         NO *no = (NO *)malloc(sizeof(NO));
         no->valor = val;
         no->col = col;
         no->prox = NULL;
         no->ant = aux;
         aux->prox = no;
      } 
      else {
         NO *no = (NO *)malloc(sizeof(NO));
         no->valor = val;
         no->col = col;
         no->prox = aux->prox;
         no->ant = aux;
         aux->prox->ant = no;
         aux->prox = no;
      }
      return 1;
   }
   return 0;  //erro
}

int remL(LISTA *lista, int lin, int col) {  //remove elemento
   if (lista != NULL) {
      NO *aux = lista->no[lin];
      if (col == 0)
         aux->valor = -1;
      else {
         for (aux = aux->prox; aux != NULL && aux->col != col; aux = aux->prox);
         if (aux != NULL && aux->prox != NULL) {
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
            free(aux);
         }
         else if (aux != NULL) {
            aux->ant->prox = NULL;
            free(aux);
         }
         else
            return -1;  //nao foi encontrado
      }
      return 1;
   }
   return 0;  //erro
}

void imprimirTr(LISTA *lista) {  //imprimir a transposta
   if (lista != NULL) {
      LISTA *trans = criarL(lista->n);
      for (int i = 0; i < lista->n; i++) {
         NO *aux = lista->no[i];
         while (aux != NULL) {
            if (aux->valor > -1) 
               setL(trans, aux->col, i, aux->valor);
            aux = aux->prox;
         }
      }
      imprimirLi(trans);
      apagarL(trans);
   }
}
