//EDSON YUDI TOMA - 9791305
#include "busca.h"
#include "matriz.h"
#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

int buscaL(MATRIX *matriz, int inicio, int fim) {
   if (matriz != NULL) {
      if (inicio == fim)
         printf("%d\n", inicio);
      else {
         char *cor = (char *)malloc(sizeof(char)*matriz->n);//= nvertices
         int *caminho = (int *)malloc(sizeof(int)*matriz->n);//= nvertices
         int *distancia = (int *)malloc(sizeof(int)*matriz->n), aux, i;//= nvertices

         for (i = 0; i < matriz->n; i++) {
            cor[i] = 'b';//branca
            distancia[i] = 0;
            caminho[i] = -1;
         } 
         cor[inicio] = 'c';//cinza
         distancia[inicio] = 0;

         FILA *fila = criarFila();
         add(fila, inicio);
         while (!vaziaFila(fila)) {
            aux = rem(fila);
            for (i = 0; i < matriz->n; i++)
               if (matriz->matriz[aux][i] > -1) {//vertice eh adjacente
                  if (cor[i] == 'b') {
                     cor[i] = 'c';
                     distancia[i] = distancia[aux] + 1;
                     caminho[i] = aux;
                     add(fila, i);
                     if (i == fim) break;//encontrou o desejado
                  }                  
               }
            if (i == fim) break;//encontrou o desejado
            cor[aux] = 'p';//preta
         }
         if (vaziaFila(fila))
            printf("\n");//nao encontrou e, portanto, apenas imprime um pulo de linha
         else {//vec eh um auxiliar para imprimir ao contrario
            int j = 0, *vec = (int *)malloc(sizeof(int));
            vec[j++] = i;//fim
            while (distancia[i]) {
               vec = (int *)realloc(vec, sizeof(int)*(j+1));
               vec[j++] = caminho[i];
               i = caminho[i];//vai voltando ate chegar no inicio
            }
            while (j > 0)//como o vetor foi preenchido como caminho invertido, imprime-se invertido
               printf("%d ", vec[--j]);
            printf("\n");
            free(vec);
         }
         apagarFila(fila);
         free(cor);
         free(distancia);
         free(caminho);
      }
   }
   return 0;
}
