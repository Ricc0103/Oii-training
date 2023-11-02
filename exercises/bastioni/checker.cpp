#include <iostream>
#include <limits>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
#define ll long long
#define inf numeric_limits<int>::max()

int pow_2(int exp){
    return 1<<exp;
}

int arrampicate(int N, string S){
    int cont = 0;
    for(int i = 0; i < N; i++){
        if(S[i] == '?'){
            cont++;
        }
    }
    int universe = pow_2(cont);
    vector<string> v(universe);
    for(int i = 0; i < N; i++){
        if(S[i] == '?'){
            for(int j = 0; j < universe; j++){
                
            }
        }
    }
}

int solve(int N, string S){
    char d = 'n';
    int r = 1;
    for(int i = 0; i < N; i++){
        char s = S[i];
        if(s == '=') continue;
        if(s == '#'){
            r++;
            d = 'n';
            
        }else if(d == '='){
            d = s;
        }else if(d == 'n'){
            d = s;
        }else if(d != s){
            r++;
            d = 'n';
        }
    }
    return r;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); // Remove these two lines in interactive problems.

  int N;
  assert(cin >> N);

  string S;
  assert(cin >> S);

  cout << solve(N, move(S)) << '\n';
  return 0;
}