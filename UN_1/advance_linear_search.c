#include <stdio.h>

int linear_search(int *, int, int);

int main() {
  int A[10];
  int search = 0;
  int len = sizeof(A) / sizeof(A[0]);

  printf("Enter elements of array: (10) -> ");
  for (int i = 0; i < len; i++) {
    scanf("%d", &A[i]);
  }

  printf("Element to search: ");
  scanf("%d", &search);

  int position = linear_search(A, len, search);

  if (position == -1)
    printf("Not found");
  else
    printf("%d found at location %d", search, position + 1);

  return 0;
}

int linear_search(int *V, int N, int element) {
  for (int i = 0; i < N; i++) {
    if (element == V[i])
      return i;
  }
  return -1;
}
