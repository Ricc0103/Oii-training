#include <string>
using namespace std;

int arrampicate(int N, string S){
    char d = 'n';
    int r = 1;
    int cont = 0;
    char first;
    for(int i = 0;i < N; i++){
        char s = S[i];
        if(s == '?'){
            if(cont == 0){
                first = d;
            }
            cont++;
            if(d == 'n' || d == '='){
                d = 'b';
            }else if(d == 'b'){
                r++;
                d = 'n';
            }else{
                d = 'n';
                r++;
            }
        }else{
            if(s == '=') continue;
            if(s == '#'){
                r++;
                d = 'n';
                
            }else if(d == 'n'){
                d = s;
                if(cont > 0){
                    if(cont % 2 == 1 && first != s){
                        d  = 'n';
                    }
                }
                
            }else if(d == 'b'){
                d = s;
                r++;
                if((first == s || first == 'n' || first == 'b')&& cont % 2 == 1){
                    d = 'n';
                }
                
            }else if(d != s){
                r++;
                d = 'n';
            }
            cont = 0;
        }
        
    }
    return r;
}
