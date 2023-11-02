#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <stdlib.h>
using namespace std;

long long int maxi = 0;

void solve(int m, string c,int n, char prec, int i = 1){
	maxi = max(maxi, stoll(c) % m);
	if(i == n){
		return;
	}
	if(prec != '6') solve(m, c +'6', n, '6', i + 1);
	if(prec != '3') solve(m, c + '3', n, '3', i + 1);
	if(prec != '9') solve(m, c + '9', n, '9', i + 1);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	for(int t = 1; t <= T; t++){
		maxi = 0;
 		int n, m;
 		cin>>n>>m;
 		for(int i = 1; i <=3; i++){
 			string temp;
 			temp.push_back(char(i * 3 + '0'));
 			solve(m, temp, n, char(i * 3 + '0'));
		}
		cout<<maxi<<" ";
	}
}