#include <assert.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define ll long long int
static FILE *fr, *fw;

// Declaring variables
static int N;
static int d;
static int L;
static int *messaggio;
static char *plaintext;

// Declaring functions
ll binary_exponentiation(int n, int exp, int M) {
	n %= M;
  ll r = 1;
  while (exp > 0) {
    if (exp % 2)
      r = r * n % M;
    exp /= 2;
    n = n * n % M;
  }
  return r;
}

void decifra(int N, int d, int L, int *messaggio, char *plaintext) {
  for (int i = 0; i < L; i++) {
    plaintext[i] = binary_exponentiation(messaggio[i], d, N);
  }
  plaintext[L] = '\0';
}

int main() {
  fr = stdin;
  fw = stdout;

  // Iterators used in for loops
  int i0;

  // Reading input
  fscanf(fr, "%d %d %d", &N, &d, &L);
  messaggio = (int *)malloc(100 * sizeof(int));
  plaintext = (char *)malloc(110 * sizeof(char));
  for (i0 = 0; i0 < L; i0++)
    fscanf(fr, "%d", &messaggio[i0]);

  // Calling functions
  decifra(N, d, L, messaggio, plaintext);

  // Writing output
  fprintf(fw, "%s\n", plaintext);

  fclose(fr);
  fclose(fw);
  return 0;
}
