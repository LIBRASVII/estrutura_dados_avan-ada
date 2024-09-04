// #include <stdio.h>
//
// int main() {
//
//   int count[] = {};
//   int i = 0, j = 0;
//   int ini = 65, fim = 91;
//
//   // for (count = 65; count < 91; count++) {
//   //   printf("  %c", count);
//   // }
//
//   for (i = ini; i < fim; i++) {
//     printf("\n %c", (char)i);
//   }
//   return 0;
// }

#include <stdio.h>
#define COLUNAS 50
#define LINHAS 50

void imprimirMatriz(int matriz[LINHAS][COLUNAS], int nLinhas, int nColunas) {
  char alfaLinha = 'A';  // Começando com o caractere 'A'
  char alfaColuna = 'A'; // Começando com o caractere 'A'

  for (int i = 0; i < nLinhas; i++) {
    if (alfaLinha < 'Z' + 1) { // ASCII dos caracteres de A a Z
      printf("%c ", alfaLinha++);
    }

    for (int j = 0; j < nColunas; j++) {
      if (alfaColuna < 'Z' + 1) {
        printf("%c ", alfaColuna++);
      }
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
    alfaColuna = 'A'; // Reinicia o alfaColuna para cada nova linha
  }
}

int main() {
  int nLinhas = 3;
  int nColunas = 4;
  int matriz[LINHAS][COLUNAS] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

  imprimirMatriz(matriz, nLinhas, nColunas);

  return 0;
}
