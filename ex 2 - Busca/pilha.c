//EDSON YUDI TOMA - 9791305
#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct NOP {
   int valor;
   struct NOP *baixo;
} NOP;

struct PILHA {
   NOP *topo;
};

NOP *criarNOP(int valor) {
   NOP *no = (NOP *)malloc(sizeof(NOP));

   if (no != NULL) {
      no->valor = valor;
      no->baixo = NULL;
   }
   return no;
}

void apagarNOP(NOP *no) {
   if (no != NULL) {
      no->baixo = NULL;
      free(no);
   }
}

PILHA *criarPilha() {
   PILHA *pilha = (PILHA *)malloc(sizeof(PILHA));
   if (pilha != NULL)
      pilha->topo = NULL;
   return pilha;
}

int vaziaPilha(PILHA *pilha) {
   if (pilha != NULL)
      return pilha->topo == NULL ? 1 : 0;
   return -1;//erro
}

int push(PILHA *pilha, int valor) {
   if (pilha != NULL) {
      if (pilha->topo == NULL)
         pilha->topo = criarNOP(valor);
      else {
         NOP *aux = pilha->topo;
         pilha->topo = criarNOP(valor);
         pilha->topo->baixo = aux;
      }
      return 1;//sucesso
   }
   return 0;//erro
}

int pop(PILHA *pilha) {
   int valor = -1;
   if (pilha != NULL) {
      if (pilha->topo != NULL) {
         NOP *aux = pilha->topo;
         pilha->topo = pilha->topo->baixo;
         valor = aux->valor;
         free(aux);
      }
   }
   return valor;//-1 = erro
}

void apagarPilha(PILHA *pilha) {
   if (pilha != NULL) {
      while (pilha->topo != NULL)
         pop(pilha);
      free(pilha);
   }
}
