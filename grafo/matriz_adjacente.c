#include <stdio.h>

int main() {
  int matriz[50][50] = {{0}};
  int nLinhas = 0, nColunas = 0;
  int posLinha = 0, posColuna = 0;
  int valor = 1;
  int op = 1;
  char alfa[26] = {};

  printf("Informe o numero de linhas => ");
  scanf("%d", &nLinhas);

  printf("Informe o numero de colunas => ");
  scanf("%d", &nColunas);

  for (int i = 0; i < nLinhas; i++) {
    for (int j = 0; j < nColunas; j++) {
      matriz[i][j] = 0;
    }
  }

  for (int i = 0; i < 26; i++) {
    alfa[i] = 'A' + i;
  }

  while (op) {
    printf("Informe a linha do vertice (1 a %d) => ", nLinhas);
    scanf("%d", &posLinha);

    printf("Informe a coluna do vertice (1 a %d) => ", nColunas);
    scanf("%d", &posColuna);

    if (posLinha >= 1 && posLinha <= nLinhas && posColuna >= 1 &&
        posColuna <= nColunas) {
      matriz[posLinha - 1][posColuna - 1] = valor;
    } else {
      printf("Posicao Invalida!\n");
    }

    printf("\n[1] => Continuar [0] => Parar  ");
    scanf("%d", &op);
  }

  printf(" ");
  for (int i = 0; i < nColunas; i++) {
    printf(" %c", 'A' + i);
  }

  for (int j = 0; j < nLinhas; j++) {
    printf("\n%c", 'A' + j);
    for (int i = 0; i < nColunas; i++) {
      printf(" %d", matriz[j][i]);
    }
  }

  for (int i = 0; i < nLinhas; i++) {
    for (int j = 0; j < nColunas; j++) {
      if (matriz[i][j] == 1)
        printf("\nV(%c)----V(%c)", alfa[i], alfa[j]);
    }
  }

  printf("\n");

  return 0;
}
