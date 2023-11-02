#include <iostream>
#define ll long long
using namespace std;
ll binpow(int n, int exp, int M) {
    n %= M;
    ll  r = 1;
    while (exp > 0) {
        if (exp & 1)
            r = r * n % M;
        n = n * n % M;
        exp >>= 1;
    }
    return r;
}

int main(){
  int n, exp, N;
  cin>>n>>exp>>N;
  cout<<binpow(n, exp, N)<<endl;
}