//EDSON YUDI TOMA - 9791305
#include "matriz.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX(a,b) a>=b ? a : b
#define MIN(a,b) a<=b ? a : b

MATRIX *criarM (int n) {
   MATRIX *matriz = (MATRIX *)malloc(sizeof(MATRIX));
   if (matriz != NULL) {
      matriz->n = n;
      matriz->matriz = (int **)malloc(sizeof(int *) * n);
      for (int i = 0; i < n; i++)
         matriz->matriz[i] = (int *)malloc(sizeof(int) * n);
      for (int i = 0; i < n; i++)
         for (int j = 0; j < n; j++)
            matriz->matriz[i][j] = -1;  //nao existem arestas ate o momento
   }
   return matriz;
}

void apagarM(MATRIX *matriz) {
   if (matriz != NULL) {
      for (int i = 0; i < matriz->n; i++)
         free(matriz->matriz[i]);
      free(matriz->matriz);
   }
   free(matriz);
}

void imprimirM(MATRIX *matriz) {
   if (matriz != NULL) {
      for (int i = 0; i < matriz->n; i++) {
         for (int j = 0; j < matriz->n; j++) {
            if (matriz->matriz[i][j] >= 0)
               printf("%d ", matriz->matriz[i][j]);
            else
               printf(". ");
         }
         printf("\n");
      }
   }
}

void imprimirL(MATRIX *matriz, int n) {  //n corresponde a linha, fc de imprimir adjacentes
   if (matriz != NULL) {
      for (int i = 0; i < matriz->n; i++)
         if (matriz->matriz[n][i] >= 0)
            printf("%d ", i);
      printf("\n");
   }
}

void imprimirT(MATRIX *matriz) {  //como o imprimir mas trocando-se linha por coluna
   if (matriz != NULL) {
      for (int i = 0; i < matriz->n; i++) {
         for (int j = 0; j < matriz->n; j++) {
            if (matriz->matriz[j][i] >= 0)
               printf("%d ", matriz->matriz[j][i]);
            else
               printf(". ");
         }
         printf("\n");
      }
   }
}

void imprimirA(MATRIX *matriz, int d) {
   if (matriz != NULL) {
      int aux = -1, lin, col;
      for (int i = 0; i < matriz->n; i++)  //encontra o menor valor
         for (int j = 0; j < matriz->n; j++)
            if (aux == -1 || (matriz->matriz[i][j] > -1 && matriz->matriz[i][j] < aux)) {
               aux = matriz->matriz[i][j];
               lin = i;
               col = j;
            }
      if (d)  //e digrafo
         printf("%d %d\n", lin, col);
      else {  //nao e digrafo
         printf("%d %d\n", MIN(lin,col), MAX(lin,col));
      }
   }
}

int setM(MATRIX *matriz, int lin, int col, int val) {  
   if (matriz != NULL) {
      matriz->matriz[lin][col] = val;
      return 1;
   }
   return 0;  //erro
}

int remM(MATRIX *matriz, int lin, int col) {
   if (matriz != NULL) {
      matriz->matriz[lin][col] = -1;  //-1 corresponde a nao existencia de arestas
      return 1;
   }
   return 0;  //erro
}
