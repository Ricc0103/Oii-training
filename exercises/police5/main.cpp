#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf numeric_limits<ll>::max()
class Edge{
  public:
  ll node;
  ll w;
  int boom;
  Edge(ll a = 0, ll b = 0, int c = 0){
    node = a;
    w = b;
    boom = c;
  }
};

class Compare{
  public:
  bool operator()(const Edge &e1, const Edge &e2){
    return e1.w > e2.w;
  }
};

ll modified_dijkstra(vector<vector<Edge>> &graph, int t){
  ll n = graph.size();
  ll src = 0;
  ll dest = n - 1;
  vector<bool> visited(n, false);
  visited[src] = true;
  priority_queue<Edge, vector<Edge>, Compare> min_heap;
  min_heap.push(Edge (src, 0, 0));
  vector<ll> distances(n, inf);
  distances[src] = 0;

  while(!min_heap.empty()){
    Edge curr = min_heap.top();
    min_heap.pop();
    visited[curr.node] = true;
    for(Edge nbr : graph[curr.node]){
      if(!visited[nbr.node]){
        if(nbr.boom == 0 || (distances[curr.node] + nbr.w <= t)){
          if(distances[curr.node] + nbr.w < distances[nbr.node]){
            distances[nbr.node] =  distances[curr.node] + nbr.w;
            min_heap.push(Edge(nbr.node, distances[nbr.node], nbr.boom));
          }
        }
      }
    }
  }
  if(distances[dest] == inf) return -1;
  return distances[dest];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input28.txt", "r", stdin);
  ll n,m,t;
  cin>>n>>m>>t;
  vector<vector<Edge>> graph(n);
  for(int i = 0; i < m; i++){
    Edge e;
    ll f;
    cin>>f>>e.node>>e.w>>e.boom;
    graph[f].push_back(e);
  }
  cout<<modified_dijkstra(graph, t)<<endl;
  return 0;
}