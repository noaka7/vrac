#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define N 8

int compar(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int *filter_duplicates(int n, int data[n], int *filtered_count) {
  // Write your code here
  // To debug: fprintf(stderr, "Debug messages...\n");'
  int *buf = (int *)malloc(n * sizeof(int));
  qsort(data, n, sizeof(int), compar);

  int i = 1, pre = data[0];
  *filtered_count = 0;
  buf[(*filtered_count)++] = data[0];
  do {
    if (pre != data[i]) {
      buf[(*filtered_count)++] = data[i];
      pre = data[i];
    }
    i++;
  } while (i < n);

  memcpy(data, buf, (*filtered_count) * sizeof(int));
  free(buf);

  return data;
}

/* Ignore and do not change the code below */
#pragma region
int main() {
  int n = N;
  int data[N] = {7, 3, 6, 4, 3, 3, 4, 9}; // 7 3 6 4 9
  // scanf("%d", &n);
  // int data[n];
  // for (int i = 0; i < n; i++) {
  //   scanf("%d", &data[i]);
  // }
  int filtered_count;
  int std_out_fd = dup(1);
  dup2(2, 1);
  int *filtered = filter_duplicates(n, data, &filtered_count);
  dup2(std_out_fd, 1);
  for (int i = 0; i < filtered_count; i++) {
    printf("%d ", filtered[i]);
  }
  puts("");

  return 0;
}
#pragma endregion
