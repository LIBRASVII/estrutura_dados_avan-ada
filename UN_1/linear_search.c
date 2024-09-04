#include <stdbool.h>
#include <stdio.h>

int main() {
  int array[] = {2, 4, 1, 5, 6, 10, 8, 9, 3};
  int var = 0;
  int len = sizeof(array) / sizeof(array[0]);
  bool found = false;

  printf("Element to search: ");
  scanf("%d", &var);

  for (int i = 0; i < len - 1; i++) {
    if (var == array[i])
      found = true;
  }

  printf("Var: %d\n", var);
  printf("Status: %s", found ? "true" : "false");

  return 0;
}
