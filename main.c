#include <stdio.h>
#include <stdlib.h>

void clearBuf() { while(getchar() != '\n'); }

void rev(int **arr, int start, int end)
{
  int range = end - start, temp;
  for (int i = 0; i < (range / 2) + 1; i++) {
    temp = (*arr)[start];

    (*arr)[start++] = (*arr)[end];
    (*arr)[end--] = temp;
  }
}

void movSeg(int **arr, int m, int n, int p)
{
  rev(arr, m, n-1);
  rev(arr, n, p);
  rev(arr, m, p);
}

int main()
{
  int *arr, size, val, m, n, p;

  printf("Enter size: ");

  while (scanf("%d", &size) == -1) {
    clearBuf();
    fflush(stdin);
    fprintf(stderr, "error: a non-number value entered!\n");
  }

  arr = calloc(size, sizeof(int));

  for (int i = 0; i < size; i++) {
    printf("Enter a value: ");
    while (scanf("%d", &val) == -1) {
      fflush(stdin);
      fprintf(stderr, "error: a non-number value entered!\n");
      printf("Enter a value: ");
    }
    arr[i] = val;
  }

  printf("\n\nEnter the start of the first segment: ");
  while (scanf("%d", &m) == -1) {
    fflush(stdin);
    fprintf(stderr, "error: a non-number value entered!\n");
  }

  printf("Enter the start of the second segment (end of the first one): ");
  while (scanf("%d", &n) == -1) {
    fflush(stdin);
    fprintf(stderr, "error: a non-number value entered!\n");
  }

  printf("Enter the end of the second segment: ");
  while (scanf("%d", &p) == -1) {
    fflush(stdin);
    fprintf(stderr, "error: a non-number value entered!\n");
  }

  if (m < 0 || n < m || p < n || p > size) {
    fprintf(stderr, "error: wrong indexes!\n");
    return -1;
  }

  printf("Before moving: ");
  for (int i = 0; i < size; i++)
    printf("%d  ", arr[i]);
  printf("\n");

  movSeg(&arr, m, n, p);

  printf("After moving: ");
  for (int i = 0; i < size; i++)
    printf("%d  ", arr[i]);
  printf("\n");

  free(arr);

  return 0;
}
