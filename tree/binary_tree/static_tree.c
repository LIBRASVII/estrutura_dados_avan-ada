// #include <stdio.h>
#include <stdlib.h>

typedef struct {
  int data;
  int left;
  int right;
  struct Tree *no;
} Tree;

int main() {
  int array[50];
  int N = 50;

  for (int i = 0; i < 50; i++) {
    array[i] = (rand() % (N + 1));
  }

  // for (int i = 0; i < 20; i++) {
  //   printf(" %d", tree[i]);
  // }

  return 0;
}

int inserir(int elem, int *root) {
  Tree *x = root;
  int n = 0;

  if (root) {
    root = elem;
  }

  if (elem <= root) {
  }

  return n;
}
