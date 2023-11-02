#include <cmath>
#define ll long long

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