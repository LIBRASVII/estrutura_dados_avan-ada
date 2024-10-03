// #include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
  int data;
  int *stack;
  struct No *top;
} No;

bool stack_empty(No *);
No *ini_stack();

int main() {
  No *no;

  stack_empty(no);
  ini_stack();

  return 0;
}

bool stack_empty(No *no) {
  if (no->top == 0)
    return true;
  else
    return false;
}

No *ini_stack() {

  No *no = malloc(sizeof(No));

  if (no == NULL) {
    no->top = 0;
    no->stack = 0;
  }

  return no;
}

No *push(No *no, int *valor) { return no; }
