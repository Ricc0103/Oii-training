#include <bits/stdc++.h>
using namespace std;

class Cell{
    public:
    int y;
    int x;
    Cell(int a, int b){
        y = a;
        x = b;
    }
};

void bfs(vector<vector<int>> &map,vector<vector<int>> &v, int i, int j){
    int n = map.size();
    int m = map[0].size();
    queue<Cell> q;
    
    q.push(Cell(i, j));
    while(!q.empty()){
        Cell curr = q.front();
        int i = curr.y;
        int j = curr.x;
        q.pop();
        v[i][j] = 1;
        //left cell
        if(j > 0 && map[i][j - 1] && !v[i][j - 1]){
            q.push(Cell(i, j - 1));
            v[i][j - 1] = 1;
        }
        //right cell
        if(j < m - 1 && map[i][j + 1] && !v[i][j + 1]){
            q.push(Cell(i, j + 1));
            v[i][j + 1] = 1;
        }
        //top cell
        if(i > 0 && map[i - 1][j] && !v[i - 1][j]){
            q.push(Cell(i - 1, j));
            v[i - 1][j] = true;
        }
        //bottom cell
        if(i < n - 1 && map[i + 1][j] && !v[i + 1][j]){
            q.push(Cell(i + 1, j));
            v[i + 1][j] = true;
        }
    }
}

int solve(vector<vector<int>> &map, int n, int m){
    
    vector<vector<int>> visited(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++){
        if(map[i][0] && !visited[i][0]){
            bfs(map, visited, i, 0);
        }
        if(map[i][m - 1] && !visited[i][m - 1]){
            bfs(map, visited, i, m - 1);
        }
        
    }
    for(int i = 0; i < m; i++){
        if(map[0][i] && !visited[0][i]){
            bfs(map, visited, 0, i);
        }
        if(map[n - 1][i] && !visited[n - 1][i]){
            bfs(map, visited, n - 1, i);
        }
    }
    int islands = 0;
    for(int i = 1; i < n - 1; i++){
        for(int j = 1; j < m - 1; j++){
            if(map[i][j] && !visited[i][j]){
                islands++;
                bfs(map, visited, i, j);
            }
        }
    }
    return islands;
}


int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> map(n, vector<int> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>map[i][j];
        }
    }
    cout<<solve(map, n, m)<<endl;
    return 0;
}