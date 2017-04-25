//EDSON YUDI TOMA - 9791305
#include "matriz.h"
#include "busca.h"
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[ ]) {
   MATRIX *matriz;
   int vertice, aresta, j, k;

   scanf("%d %d", &vertice, &aresta);//le a qtd de vertices e arestas
   matriz = criarM(vertice);//cria a matriz
   for (int i = 0; i < aresta; i++) {
      scanf("%d %d", &j, &k);//le os vertices q compoem cada aresta
      setM(matriz, j, k, 1);   //valores sempre 1
   }
   while (scanf("%d %d", &j, &k) != EOF)//faz a busca ate o fim do arquivo
      buscaL(matriz, j, k);

   apagarM(matriz);//libera memoria
}
