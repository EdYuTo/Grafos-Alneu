//EDSON YUDI TOMA - 9791305
#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct NOF {
   int valor;
   struct NOF* proximo;
   struct NOF* anterior;
} NOF;

struct FILA {
   NOF *inicio;
   NOF *fim;
};

NOF *criarNOF(int valor) {
   NOF *no = (NOF *)malloc(sizeof(NOF));

   if (no != NULL) {
      no->valor = valor;
      no->proximo = NULL;
      no->anterior = NULL;
   }
   return no;
}

void apagarNOF(NOF *no) {
   if (no != NULL) {
      no->proximo = NULL;
      no->anterior = NULL;
      free(no);
   }
}

FILA *criarFila() {
   FILA *fila = (FILA *)malloc(sizeof(FILA));
   if (fila != NULL) {
      fila->inicio = NULL;
      fila->fim = NULL;
   }
   return fila;
}

int vaziaFila(FILA *fila) {
   if (fila != NULL) 
      return fila->inicio == NULL ? 1 : 0;
   return -1;//erro
}

int add(FILA* fila, int valor) {
   if (fila != NULL) {
      if (fila->inicio == NULL) {
         fila->inicio = criarNOF(valor);
         fila->fim = fila->inicio;
      } else {
         fila->fim->proximo = criarNOF(valor);
         fila->fim->proximo->anterior = fila->fim;
         fila->fim = fila->fim->proximo;
      }
      return 1;//sucesso
   }
   return 0;//erro
}

int rem(FILA *fila) {
   int valor = -1;
   if (fila != NULL) {
      if (fila->inicio == fila->fim && fila->inicio != NULL) {
         valor = fila->inicio->valor;
         apagarNOF(fila->inicio);
         fila->inicio = NULL;
         fila->fim = NULL;
      } else if (fila->inicio != NULL) {
         valor = fila->inicio->valor;
         fila->inicio = fila->inicio->proximo;
         apagarNOF(fila->inicio->anterior);
         fila->inicio->anterior = NULL;
      }
   }
   return valor;//-1 = erro
}

void apagarFila(FILA *fila) {
   if (fila != NULL) {
      while (fila->inicio != NULL)
         rem(fila);
      free(fila);
   }
}
