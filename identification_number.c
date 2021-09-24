#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pow_ten(int n) {
  int acc = 1;
  for (int i = 0; i < n; i++) {
    acc *= 10;
  }
  return acc;
}

int compute_check_digit(char identification_number[13]) {
  int ans;
  int sum_even = 0, sum_odd = 0;
  int n = atoi(identification_number);
  int len = strlen(identification_number);
  for (int d, i = len; 0 < i; i--) {
    d = n / pow_ten(i - 1) % 10;
    if (i & 1) {
      sum_even += d;
    } else {
      sum_odd += d;
    }
  }
  ans = (sum_even * 3 + sum_odd) % 10;
  if (ans) {
    ans = 10 - ans;
  }
  return ans;
}

int main(int argc, char *argv[]) {
  char *id = "39847";
  int ans = compute_check_digit(id);
  printf("%d\n", compute_check_digit(id));
  assert(ans == 3);

  return 0;
}
