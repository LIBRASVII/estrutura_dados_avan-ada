#include <stdio.h>
#define TAMANHO_HEAP 7

void max_heapify(int[], int, int);
void biuld_max_heap(int[]);
void heap_sort(int[], int);
void swap(int *, int *);

int main() {
  int array[] = {10, 2, 4, 30, 34, 50, 67, '\n'};

  for (int i = 0; i < TAMANHO_HEAP; i++) {
    printf(" %d", array[i]);
  }
  printf("\n");

  heap_sort(array, TAMANHO_HEAP);

  for (int i = 0; i < TAMANHO_HEAP; i++) {
    printf(" %d", array[i]);
  }
  printf("\n");

  return 0;
}

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void max_heapify(int A[], int tam, int i) {
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  int largest = i;

  if (left <= TAMANHO_HEAP && A[left] > A[i])
    largest = left;

  if (right <= TAMANHO_HEAP && A[right] > A[largest])
    largest = right;

  if (largest != i) {
    swap(&A[i], &A[largest]);
    max_heapify(A, tam, largest);
  }
}

void build_max_heap(int A[], int tam) {
  for (int i = tam / 2 - 1; i >= 0; i--) { // inicia do último nó não folha
    max_heapify(A, tam, i);
  }
}

// Ordena o heap de max
void heap_sort(int A[], int tam) {
  build_max_heap(A, tam);

  for (int i = tam - 1; i > 0; i--) {
    swap(&A[0], &A[i]); // move a atual raiz para o fim
    max_heapify(A, i, 0);
  }
}
