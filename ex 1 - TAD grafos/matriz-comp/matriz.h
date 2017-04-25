#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct matrix {
   int n; //numero de linhas/colunas
   int **matriz;
} MATRIX;

MATRIX *criarM(int n);  //criar matriz
void apagarM(MATRIX *matriz);  //apagar matriz
void imprimirM(MATRIX *matriz);  //imprimir matriz
void imprimirL(MATRIX *matriz, int n);  //imprimir uma linha da matriz
void imprimirT(MATRIX *matriz);  //imprimir a transposta
void imprimirA(MATRIX *matriz, int d);  //imprimir uma aresta, d indica se e um digrafo(1) ou nao(0)
int setM(MATRIX *matriz, int lin, int col, int val);  //adicionar um valor na matriz
int remM(MATRIX *matriz, int lin, int col);  //remove elemento

#endif 
