//EDSON YUDI TOMA - 9791305
#include "busca.h"
#include "matriz.h"
#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

void visit(int u, MATRIX *matriz, int fim, char *cor, int *anterior) {
   cor[u] = 'c';//cinza
   
   for (int i = 0; i < matriz->n; i++) {
      if (matriz->matriz[u][i] > -1) {
         if (cor[i] == 'b') {
            anterior[i] = u;
            visit(i, matriz, fim, cor, anterior);
         }
      }
   }
   cor[u] = 'p';//preto
}

int buscaP(MATRIX *matriz, int inicio, int fim) {
   if (matriz != NULL) {
      if (inicio != fim && fim < matriz->n) {
         char *cor = (char *)malloc(sizeof(char)*matriz->n);
         int *anterior = (int *)malloc(sizeof(int)*matriz->n);
         int *caminho = (int *)malloc(sizeof(int)), i, j = 1;
         caminho[0] = fim;

         for (i = 0; i < matriz->n; i++) {
            cor[i] = 'b';//branco
            anterior[i] = -1;//nao usado
         }
         visit(inicio, matriz, fim, cor, anterior);
         i = fim;

         while (anterior[i] != -1) {//parar quando chegar no primeiro
            caminho = (int *)realloc(caminho, sizeof(int)*(j+1));
            caminho[j++] = anterior[i];
            i = anterior[i];
         }
         while (j > 0 && anterior[fim] != -1)//parar quando chegar no primeiro
            printf("%d ", caminho[--j]);//imprime ao contrario
         free(cor);
         free(anterior);
         free(caminho);
      } else if (fim < matriz->n)//se for igual ja esta no lugar!
         printf("%d", inicio);
      printf("\n");
   }
   return 0;
}
