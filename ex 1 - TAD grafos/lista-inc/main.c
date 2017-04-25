#include "lista.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[ ]) {
   LISTA *lista;
   char direcionado, ml, inst[4];
   int vertice, aresta, i, j, val;

   scanf("%c %c %d %d", &direcionado, &ml, &vertice, &aresta);
   
   if (ml == 'L') {  //se for lista
      lista = criarL(vertice);
      for (int k = 0; k < aresta; k++) {
         scanf("%d %d %d", &i, &j, &val);
         setL(lista, i, j, val);
         if (direcionado == 'G')  //se nao for direcionado
            setL(lista, j, i, val);
      }  
      while (scanf("%s", inst) != EOF) {
         if (strcmp(inst, "IG") == 0)
            imprimirLi(lista);
         else if (strcmp(inst, "VA") == 0) {
            scanf("%d", &val);
            imprimirRo(lista, val);
         }
         else if (strcmp(inst, "AA") == 0) {
            scanf("%d %d %d", &i, &j, &val);
            setL(lista, i, j, val);
            if (direcionado == 'G')  //se nao for direcionado
               setL(lista, j, i, val);
         }
         else if (strcmp(inst, "RA") == 0) {
            scanf("%d %d", &i, &j);
            remL(lista, i, j);
            if (direcionado == 'G')
               remL(lista, j, i);
         }
         else if (strcmp(inst, "IT") == 0) {
            if (direcionado == 'D') {
               imprimirTr(lista);
            }
         }
         else if (strcmp(inst, "MP") == 0)
            imprimirAr(lista, (direcionado == 'G'));
      }
      apagarL(lista);
   } 
   return 0;
}
