#include <string>
using namespace std;

int arrampicate(int N, string S){
   char d = 'n';
    int r = 1;
    for(char s : S){
        if(s == '=') continue;
        if(s == '#'){
            r++;
            d = 'n';
        }else if(d == '=' || d == 'n'){
            d = s;
        }else if(d != s){
            r++;
            d = 'n';
        }
    }
    return r;
}
