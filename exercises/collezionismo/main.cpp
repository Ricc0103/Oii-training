#include <bits/stdc++.h>
using namespace std;
#define ll long long
int solve(vector<ll> &v, ll k){
  ll n = v.size();
  sort(v.begin(), v.end());
  vector<ll> d(n - 1);
  for(ll i = 0; i < n - 1; i++){
    d[i] = v[i + 1] - v[i];
  }
  sort(d.begin(), d.end(), greater<ll>());
  ll r = v[n - 1] - v[0];
  for(ll i = 0; i < k - 1; i++){
    r -= d[i];
  }
  return r;

/*   map<ll,ll> m;
  for(ll i = 0; i < k; i++){
    m[d[i]]++;
  }
  ll c = 1;
  ll f;
  ll r = 0;
  for(ll i = 0; i < n; i++){
    if(c){
      c = 0;
      f = v[i];
    }
    if(m[v[i + 1] - v[i]] > 0){
      m[v[i + 1] - v[i]]--;
      r += (v[i] - f);
      c = 1;
    } 
  }
  return r; */
}

int main(){
  freopen("collezionismo_input_3.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  ll T;
  cin>>T;
  for(ll t = 1; t <= T; t++){
    ll n, k;
    cin>>n>>k;
    vector<ll> v(n);
    for(ll &e : v){
      cin>>e;
    }
    cout<<"Case #"<<t<<": "<<solve(v, k)<<endl;
  }
  return 0;
}