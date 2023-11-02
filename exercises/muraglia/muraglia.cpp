#include <bits/stdc++.h>
using namespace std;

struct segmentTree {
  int n;
  vector<int> st;

  void init(int _n = 0) {
    this->n = _n;
    st.resize(n * 4, 0);
  }

  void build(int start, int end, int node, vector<int> &v) {
    if (start >= end) {
      st[node] = v[start];
      return;
    }
    int mid = (start + end) / 2;
    build(start, mid, 2 * node + 1, v);
    build(mid + 1, end, 2 * node + 2, v);
    st[node] = max(st[2 * node + 1], st[2 * node + 2]);
  }

  void build(vector<int> &v) { build(0, n - 1, 0, v); }

  int query(int start, int end, int l, int r, int node) {
    if (start > r || end < l)
      return 0;
    if (l <= start && r >= end)
      return st[node];
    int mid = (start + end) / 2;
    int left_side = query(start, mid, l, r, 2 * node + 1);
    int right_side = query(mid + 1, end, l, r, 2 * node + 2);
    return max(left_side, right_side);
  }

  int query(int l, int r) { return query(0, n - 1, l, r, 0); }

  void update(int start, int end, int node, int target, int value) {
    if (start >= end) {
      st[node] = value;
      return;
    }
    int mid = (start + end) / 2;
    if (target <= mid) {
      update(start, mid, 2 * node + 1, target, value);
    } else {
      update(mid + 1, end, 2 * node + 2, target, value);
    }
    st[node] = max(st[2 * node + 1], st[2 * node + 2]);
    return;
  }

  void update(int target, int value) { update(0, n - 1, 0, target, value); }
};

segmentTree sT;
int n, l, r, target;

int get_succ(int n, int lv, int rv) {
  if (lv > r || rv < l) return -1;
  if (l <= lv && rv <= r) {
    if (sT.st[n] <= target) return -1;
    while (lv != rv) {
      int m = lv + (rv - lv) / 2;
      if (sT.st[2 * n + 1] > target) {
        n = 2 * n + 1;
        rv = m;
      } else {
        n = 2 * n + 2;
        lv = m + 1;
      }
    }
    return lv;
  }
  int mid = lv + (rv - lv) / 2;
  int rs = get_succ(2 * n + 1, lv, mid);
  if (rs != -1) return rs;
  return get_succ(2 * n + 2, mid + 1, rv);
}

int get_prec(int n, int lv, int rv) {
  if (lv > r || rv < l) return -1;
  if (l <= lv && rv <= r) {
    if (sT.st[n] <= target) return -1;
    while (lv != rv) {
      int m = lv + (rv - lv) / 2;
      if (sT.st[2 * n + 2] > target) {
        n = 2 * n + 2;
        lv = m + 1;
      } else {
        n = 2 * n + 1;
        rv = m;
      }
    }
    return lv;
  }
  int mid = lv + (rv - lv) / 2;
  int ls = get_prec(2 * n + 2, mid + 1, rv);
  if (ls != -1) return ls;
  return get_prec(2 * n + 1, lv, mid);
}

pair<int,int> chiedi(int x) {
  target = sT.query(x, x);
  l = x;
  r = n - 1;
  int succ = get_succ(0, 0, n - 1);
  
  l = 0;
  r = x;
  int prec = get_prec(0, 0, n - 1);
  prec = max(0, prec);
  if (succ == -1) succ = n - 1;
  return make_pair(prec, succ);
}

void cambia(int x, int h) {
  sT.update(x, h);
  return;
}

void inizializza(int N, vector<int> H) {
  n = N;
  sT.init(N);
  sT.build(H);
  return;
}

int main() {
  int m;
  cin >> n >> m;
  vector<int> H(n);
  for (int i = 0; i < n; i++) {
    cin >> H[i];
  }
  inizializza(n, H);
  for (int i = 0; i < m; i++) {
    char t;
    cin >> t;
    if (t == 'Q') {
      int a;
      cin >> a;
      pair<int,int> p = chiedi(a);
      cout<<p.first<<" "<<p.second<<endl;
    } else {
      int a, b;
      cin >> a >> b;
      cambia(a, b);
    }
  }
  return 0;
}
