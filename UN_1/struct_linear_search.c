#include <stdio.h>
#include <string.h>
#include <strings.h>

#define clear() printf("\033[H\033[J")

typedef struct Pessoa {
  char nome[50];
  int idade;
  char email[50];
} Pessoa;

int buscarPessoaPorNome(struct Pessoa[], int, const char[]);
int verificaDuplicidade(struct Pessoa[], int, const char[]);
int excluirPessoa(struct Pessoa[], int, const char[]);

int main() {
  struct Pessoa pessoa[10];
  int numPessoas = 0;
  int op = 1;
  char nomeBuscado[50];

  while (op) {
    printf("\t---  Busca Linear ---\n");
    printf("\t--- Vetor de Struct ---\n");
    printf("\n[01] ==> Inserir Elemento\n");
    printf("[02] ==> Buscar Elemento\n");
    printf("[03] ==> Exibir Elemento\n");
    printf("[04] ==> Deletar Elemento\n");
    printf("[00] ==> Sair\n");
    printf(" ==> Informe Opcao: ");
    scanf("%d", &op);

    switch (op) {
    case 1:
      if (numPessoas < 10) {
        clear();
        printf("[01] ==> Inserir Elemento\n");
        printf("Nome: ");
        scanf("%s", pessoa[numPessoas].nome);

        if (verificaDuplicidade(pessoa, numPessoas, pessoa[numPessoas].nome) ==
            -1) {
          printf("\nDuplicidade encontrada\n");
        } else {
          printf("Idade: ");
          scanf("%d", &pessoa[numPessoas].idade);
          printf("Email: ");
          scanf("%s", pessoa[numPessoas].email);
          printf("\n");
          numPessoas++;
        }
      } else {
        clear();
        printf("==> Limite de pessoas excedido\n");
      }
      break;
    case 2:
      if (numPessoas > 0) {
        clear();
        printf("[02] ==> Buscar Elemento\n");
        printf("==> Nome a ser buscado: ");
        scanf("%s", nomeBuscado);

        int index = buscarPessoaPorNome(pessoa, numPessoas, nomeBuscado);

        if (index != -1) {
          printf("==> Pessoa encotrada\n");
          printf("==> Nome: %s\n", pessoa[index].nome);
          printf("==> Idade: %d\n", pessoa[index].idade);
          printf("==> Email: %s\n", pessoa[index].email);
        } else {
          printf("==> Atencao! Pessoa nao encontrada\n");
        }
      } else {
        clear();
        printf("==> Atencao! Vetor vazio\n");
      }
      break;
    case 3:
      if (numPessoas) {
        for (int i = 0; i < numPessoas; i++) {
          printf("==> Nome: %s\n", pessoa[i].nome);
          printf("==> Idade: %d\n", pessoa[i].idade);
          printf("==> Email: %s\n", pessoa[i].email);
        }
      } else {
        clear();
        printf("==> Vetor vazio!\n");
      }
      break;

    case 4:
      if (numPessoas > 0) {
        printf("\n==> Pessoa a ser excluida: ");
        scanf("%s", nomeBuscado);

        int novoNumPessoa = excluirPessoa(pessoa, numPessoas, nomeBuscado);

        if (novoNumPessoa != -1) {
          clear();
          numPessoas = novoNumPessoa; // Update the number of people
          printf("==> Pessoa excluida!\n");
        }
      } else {
        clear();
        printf("Vetor vazio!\n");
      }
      break;
    case 0:
      clear();
      printf("==> Programa encerrado...\n");
      break;
    default:
      clear();
      printf("==> Opcao invalida...\n");
    }
  }
  return 0;
}

int buscarPessoaPorNome(struct Pessoa pessoa[], int n, const char nome[]) {
  for (int i = 0; i < n; i++) {
    if (strcmp(pessoa[i].nome, nome) == 0) {
      return i;
    }
  }
  return -1;
}

int verificaDuplicidade(struct Pessoa pessoa[], int n, const char nome[]) {
  for (int i = 0; i < n; i++) {
    if (strcmp(pessoa[i].nome, nome) == 0) {
      return -1;
    }
  }
  return 1;
}

int excluirPessoa(struct Pessoa pessoa[], int n, const char nome[]) {
  int index = -1;

  for (int i = 0; i < n; i++) {
    if (strcmp(pessoa[i].nome, nome) == 0) {
      index = i;
      break;
    }
  }
  if (index == -1) {
    printf("Não encontrado\n");
    return -1;
  } else {
    for (int i = index; i < n - 1; i++) {
      pessoa[i] = pessoa[i + 1];
    }
    return n - 1;
  }
}
