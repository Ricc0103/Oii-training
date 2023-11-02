#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  set<ll> s;
  for(int i = 0; i < 5; i++){
    ll temp;
    cin>>temp;
    s.insert(temp);
  }
  ll n;
  cin>>n;
  for(ll el : s){
    cout<<el<<" ";
  }
  cout<<endl;
  set<ll>::iterator low, up;
  low = s.lower_bound(n);
  up = s.upper_bound(n);
  if(low != s.begin()){
    low--;
  }
  cout<<*low<<" "<<*up<<endl;
  return 0;
}