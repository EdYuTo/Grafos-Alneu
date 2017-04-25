#include "matriz.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[ ]) {
   MATRIX *matriz;
   char direcionado, ml, inst[4];
   int vertice, aresta, i, j, val;

   scanf("%c %c %d %d", &direcionado, &ml, &vertice, &aresta);
   
   if (ml == 'M') {  //se for matriz
      matriz = criarM(vertice);
      for (int k = 0; k < aresta; k++) {
         scanf("%d %d %d", &i, &j, &val);
         setM(matriz, i, j, val);
         if (direcionado == 'G')  //se nao for direcionado
            setM(matriz, j, i, val);
      }  
      while (scanf("%s", inst) != EOF) {
         if (strcmp(inst, "IG") == 0)
            imprimirM(matriz);
         else if (strcmp(inst, "VA") == 0) {
            scanf("%d", &val);
            imprimirL(matriz, val);
         }
         else if (strcmp(inst, "AA") == 0) {
            scanf("%d %d %d", &i, &j, &val);
            setM(matriz, i, j, val);
            if (direcionado == 'G')  //se nao for direcionado
               setM(matriz, j, i, val);
         }
         else if (strcmp(inst, "RA") == 0) {
            scanf("%d %d", &i, &j);
            remM(matriz, i, j);
            if (direcionado == 'G')
               remM(matriz, j, i);
         }
         else if (strcmp(inst, "IT") == 0) {
            if (direcionado == 'D') {
               imprimirT(matriz);
            }
         }
         else if (strcmp(inst, "MP") == 0)
            imprimirA(matriz, (direcionado == 'G'));
      }
      apagarM(matriz);
   } 
   else {  //lista
   }
   return 0;
}
