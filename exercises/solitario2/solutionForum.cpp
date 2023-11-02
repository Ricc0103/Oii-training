#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
int area;

void stampa_matrix(vector<vector<int>>& tris) {  // solamente per debugging
    for (int i = 0; i < tris.size(); i++) {
        for (int j = 0; j < tris[i].size(); j++) {
            cout << tris[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

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

int gioca(int x, int y, vector<vector<int>>& tris, int curr, int max_found) {  // funzione recursiva
    if (x >= N) {                                                              // se è finita la riga
        return gioca(0, y + 1, tris, curr, max_found);
    }

    if (y >= M) {  // se sono finite le colonne, quindi si è visto tutto
        return curr;
    }

    int piazzate = (N * y) + x;
    if (ceil(((area - piazzate) * (float)2 / 3) + curr) < max_found) {  // ottimizzazione che ti fa fare 60 pt (avrei voluto scoprirlo prima)
        return -1;                                                      // per farla breve, se le x di questa soluzione + i 2/3 delle caselle libere < il totale che ho già trovato in un altra soluzione
    }                                                                   // non ha senso continuare
    //^ casi base

    // casi specifici
    int res = 0;


    bool safe = check(tris, x, y);
    int tmp = tris[y][x]; 
    if (safe) {
        tris[y][x] = 1;
        res = gioca(x + 1, y, tris, curr + 1, max(res, max_found));
        if (!tmp) tris[y][x] = 0;                                 
    }

    if (tmp) {
        return max(res, max_found);
    } else {
        return max(res, gioca(x + 1, y, tris, curr, max(res, max_found))); 
    }
}

int main() {
    cin >> N >> M;
    assert(cin.good());

    int found = 0;
    vector<vector<int>> G(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int tmp;
            cin >> tmp;

            G[i][j] = tmp;
            if (tmp) {
                found++;  // con una variabile tengo conto delle x già presenti nell'input
            }
        }
    }

    area = N * M;  // mi serve per l'ottimizzazione

    int tmp = N;  // scambio le variabili per renderla compatibile con il codice scritto sopra
    N = M;
    M = tmp;

    int res = gioca(0, 0, G, 0, found);  //(x, y, &matrix, curr, max_found)
    cout << res - found << endl;         // al risultato tolgo quelle già trovate
}