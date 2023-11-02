#include <iostream>
#include <cassert>
#include <utility>
#include <vector>
#include <limits>
#include <set>
#include <cmath>
#define ll long long
#define inf numeric_limits<ll>::max()
using namespace std;
set<ll> s;

void inizia() {

    return;
}

void apri(long long p) {
    s.insert(p);
    return;
}

void chiudi(long long p) {
    s.erase(p);
    return;
}

long long chiedi(long long p) {
    if(s.empty()) return -1;
    set<ll>::iterator left, right;
    left = s.lower_bound(p);
    right = s.upper_bound(p);
    if(left != s.begin() && *left != p){
        left--;
    }
    if(abs(*left - p) < abs(*right - p)){
        return *left;
    }
    return *right;
}


int main() {
    int Q;
    cin >> Q;

    inizia();

    for (int i = 0; i < Q; i++){
        long long p;
        char t;
        cin >> t >> p;
        if (t == 'a') apri(p);
        else if (t == 'c') chiudi(p);
        else cout << chiedi(p) << endl;
    }

    return 0;
}
