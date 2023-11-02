#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Edge{
  public:
  ll to;
  ll w;
  int boom;
  Edge(ll a = 0, ll b = 0, int c = 0){
    to = a;
    w = b;
    boom = c;
  }
  
};



int main(){
  Edge e(5, 3, 2);
  cout<<e->to<<endl;
  cout<<e.to<<endl;
}