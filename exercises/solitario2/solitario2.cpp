#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
using namespace std;
bool check(vector<vector<int>> &g, int i, int j){
    if(g[i][j] == 1) return false;
    int n = g.size();
    int m = g[0].size();
    //upper-left diagonal
    if(i > 1 && j > 1 && !(g[i - 1][j - 1] == 0 || g[i - 2][j - 2] == 0)) return false;
    //upper-right diagonal
    if(i > 1 && j < m - 2 && !(g[i - 1][j + 1] == 0 || g[i - 2][j + 2] == 0)) return false;
    //lower-left diagonal
    if(i < n - 2 && j > 1 && !(g[i + 1][j - 1] == 0 || g[i + 2][j - 2] == 0)) return false;
    //lower-right diagonal
    if(i < n - 2 && j < m - 2 && !(g[i + 1][j + 1] == 0 || g[i + 2][j + 2] == 0)) return false;
    //middle-down diagonal \|
    if(i > 0 && i < n - 1 && j > 0 && j < m - 1 && !(g[i - 1][j - 1] == 0 || g[i + 1][j + 1] == 0)) return false;
    //middle-up diagonal /
    if(i > 0 && i < n - 1 && j > 0 && j < m - 1 && !(g[i - 1][j + 1] == 0 || g[i + 1][j - 1] == 0)) return false;
    //left row
    if(j > 1 && !(g[i][j - 1] == 0 || g[i][j - 2] == 0)) return false;
    //right row
    if(j < m - 2 && !(g[i][j + 1] == 0 || g[i][j + 2] == 0)) return false;
    //up row
    if(i > 1 && !(g[i - 1][j] == 0 || g[i - 2][j] == 0)) return false;
    //down row
    if(i < n - 2 && !(g[i + 1][j] == 0 || g[i + 2][j] == 0)) return false;
    //middle x row
    if(j > 0 && j < m - 1 && !(g[i][j - 1] == 0 || g[i][j + 1] == 0)) return false;
    // middle y row
    if(i > 0 && i < n - 1 && !(g[i + 1][j] == 0 || g[i - 1][j] == 0)) return false;
    return true;
}
int gioca(int N, int M, vector<vector<int>> G, int maxi = 0, int i = 0, int j = 0, int score = 0){
    if(j == M){
        j = 0;
        i++;
    }
    if(i == N) return score;
    int cell_left = N * M - (M * i + j);
    int best_case = ceil(cell_left * (float)2/3 + score);
    if(best_case < maxi){
        return score;
    }
    
    int put = 0;
    if(check(G, i, j)){
        G[i][j] = 1;
        put = gioca(N, M, G, max(put, maxi) ,i, j + 1, score + 1);
        G[i][j] = 0;
    }
    int no_put = gioca(N, M, G, max(maxi, put), i, j + 1,score);
    return max(no_put, put);
}

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N, vector<int>(M));
    for(auto& x : G){
        for(auto& y : x){
            cin >> y;
        }

    }
    cout << gioca(N, M, G)<< endl;
}
