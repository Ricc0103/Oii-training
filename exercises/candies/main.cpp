#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf numeric_limits<int>::max()

int main(){
  int n;
  cin>>n;
  vector<int> v(n);
  for(int i = 0; i < n; i++){
    cin>>v[i];
  }
  sort(v.begin(), v.end());
  int cont = 1;
  ll tot = 1;
  for(int i = 1; i < n; i++){
    if(v[i] != v[i - 1]) cont++;
    tot+=cont;
  }
  cout<<tot<<endl;
  return 0;
}