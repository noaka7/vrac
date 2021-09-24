#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define N 257

char buf[2 * N];

bool is_vowel(char c) { return strchr("aeiouy", c); }

int min(int a, int b) { return a < b ? a : b; }

char *translate(char text[N]) {
  // Write your code here
  // To debug: fprintf(stderr, "Debug messages...\n");'
  int j = 0;
  int len = min(strlen(text), N);
  for (int i = 0; i < len && j < N; i++) {
    if (is_vowel(text[i]) && (0 == i || !is_vowel(text[i - 1]))) {
      buf[j++] = 'a';
      buf[j++] = 'v';
    }
    buf[j++] = text[i];
  }
  return buf;
}

/* Ignore and do not change the code below */
#pragma region
int main() {
  char text[257] = "hello, secret meeting tonight.";
  // scanf("%[^\n]", text);
  int std_out_fd = dup(1);
  dup2(2, 1);
  char *javanais = translate(text);
  dup2(std_out_fd, 1);
  printf("%s\n", javanais);
  assert(0 ==
         strcmp("havellavo, savecravet maveetaving tavonavight.", javanais));

  return 0;
}
#pragma endregion
