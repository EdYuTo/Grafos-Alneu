//EDSON YUDI TOMA - 9791305
#include "matriz.h"
#include "lista.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[ ]) {
   MATRIX *matriz;
   LISTA *lista;
   char direcionado, ml, inst[4];
   int vertice, aresta, i, j, val;

   scanf("%c %c %d %d", &direcionado, &ml, &vertice, &aresta);
   
   if (ml == 'M') {  //se for matriz
      matriz = criarM(vertice);  //aloca a matriz
      for (int k = 0; k < aresta; k++) {
         scanf("%d %d %d", &i, &j, &val);  //le os valores de linha, coluna e valor para inserilos na matriz
         setM(matriz, i, j, val);
         if (direcionado == 'G')  //se nao for direcionado
            setM(matriz, j, i, val);
      }  
      while (scanf("%s", inst) != EOF) {  //comandos com parada no fim de arquivo
         if (strcmp(inst, "IG") == 0)  //imprime
            imprimirM(matriz);
         else if (strcmp(inst, "VA") == 0) {  //imprime vertices adjacentes
            scanf("%d", &val);
            imprimirL(matriz, val);
         }
         else if (strcmp(inst, "AA") == 0) {  //adciona uma aresta
            scanf("%d %d %d", &i, &j, &val);
            setM(matriz, i, j, val);
            if (direcionado == 'G')  //se nao for direcionado
               setM(matriz, j, i, val);
         }
         else if (strcmp(inst, "RA") == 0) {  //remove uma aresta
            scanf("%d %d", &i, &j);
            remM(matriz, i, j);
            if (direcionado == 'G')
               remM(matriz, j, i);
         }
         else if (strcmp(inst, "IT") == 0) {  //imprime transposta
            if (direcionado == 'D') {
               imprimirT(matriz);
            }
         }
         else if (strcmp(inst, "MP") == 0)  //imprime menor aresta
            imprimirA(matriz, (direcionado == 'D'));
      }
      apagarM(matriz);  //libera a memoria
   } 
   else if (ml == 'L'){  //lista
      lista = criarL(vertice);  //aloca a lista
      for (int k = 0; k < aresta; k++) {
         scanf("%d %d %d", &i, &j, &val);  //le os valores de linha, coluna e valor para inseri-los na lista
         setL(lista, i, j, val);
         if (direcionado == 'G')  //se nao for direcionado
            setL(lista, j, i, val);
      }  
      while (scanf("%s", inst) != EOF) {  //comandos com parada no fim de arquivo
         if (strcmp(inst, "IG") == 0)  //imprime a lista
            imprimirLi(lista);
         else if (strcmp(inst, "VA") == 0) {  //imprime os vertices adjacentes
            scanf("%d", &val);
            imprimirRo(lista, val);
         }
         else if (strcmp(inst, "AA") == 0) {  //adiciona uma aresta
            scanf("%d %d %d", &i, &j, &val);
            setL(lista, i, j, val);
            if (direcionado == 'G')  //se nao for direcionado
               setL(lista, j, i, val);
         }
         else if (strcmp(inst, "RA") == 0) {  //remove uma aresta
            scanf("%d %d", &i, &j);
            remL(lista, i, j);
            if (direcionado == 'G')
               remL(lista, j, i);
         }
         else if (strcmp(inst, "IT") == 0) {  //imprime a transposta
            if (direcionado == 'D') {
               imprimirTr(lista);
            }
         }
         else if (strcmp(inst, "MP") == 0)  //imprime a menor aresta
            imprimirAr(lista, (direcionado == 'D'));
      }
      apagarL(lista);  //libera a memoria
   } 
   return 0;
}
