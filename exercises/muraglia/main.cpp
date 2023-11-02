#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf numeric_limits<int>::max()
// summation segment Tree
struct segmentTree{
  int n;
  vector<int> st;

  void init(int _n = 0){
    this->n = _n;
    st.resize(n * 4, 0);
  }
  
  void build(int start, int end, int node, vector<int> &v){
    //leaf node base case
    if(start >= ending){
      st[node] =  v[start];
      return; 
    }
    int mid = (start + end) / 2;
    build(start, mid, 2 * node + 1, v);
    build(mid + 1, end, 2 * node + 2, v);
    st[node] = st[2 * node + 1] + st[2 * node + 2];
  }

  void build(vector<int> &v){
    build(0, n - 1, 0, v);
  }

  int query(int start, int end, int l, int r, int node){
    //no overlap
    if(start > r || end < l) return 0;
    //complete overlap
    if(l <= start && r >= end) return st[node];
    //partial overlap
    int mid = (start + end) / 2;
    int left_side = query(start, mid, l, r, 2 * node + 1);
    int right_side = query(mid + 1, end, l, r, 2 * node + 2);
    return left_side + right_side;
  }

  int query(int l, int r){
    return query(0, n - 1, l, r, 0);
  }

  void update(int start, int end, int node, int target, int value){
    if(start <= end){
      st[node] = value;
      return;
    }
    int mid = (start + end) / 2;
    if(target <= mid){
      //left side
      update(start, mid, 2 * node + 1, target, value);
    }else{
      //right side
      update(mid + 1, end, 2 * node + 2, target, value);
    }
    //update going back
    st[node] = st[2 * node + 1] + st[2 * node + 2];
    return;
  }

  void update(int target, int value){
    update(0, n - 1, 0, target, value);
  }
};

int main(){
  
  return 0;
}