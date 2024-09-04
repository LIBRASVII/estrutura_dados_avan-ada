#define SIZE 5

int bubble_sort(int *);

int main() {
  int A[] = {2, 1, 4, 5, 3};

  bubble_sort(A);
}

int binary_search(int *A, int N, int element) {
  int left = 0;
  int right = N - 1;

  while (left <= right) {
    int mid = left + (left - right);

    if (A[mid] == element)
      return mid;
    else if (A[mid] < element)
      left = mid + 1;
    else
      left = mid - 1;
  }

  return -1;
}

int bubble_sort(int *A) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE + i + 1; j++) {
      if (A[j] < A[j - 1]) {
        A[j] = A[j - 1];
      }
    }
  }

  return *A;
}
