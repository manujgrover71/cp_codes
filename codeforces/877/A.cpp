#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define ll long long


int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str; cin >> str;

    int Danial = 0, Olya = 0, Slava = 0, Ann = 0, Nikita = 0;

    for(int i = 0; i < str.length(); i++){
        if( i+4 < str.length() && str[i] == 'D' && str[i+1] == 'a' && str[i+2] == 'n' && str[i+3] == 'i' && str[i+4] == 'l'){
            Danial += 1;
        }
        if( i+3 < str.length() && str[i] == 'O' && str[i+1] == 'l' && str[i+2] == 'y' && str[i+3] == 'a'){
            Olya += 1;
        }
        if( i+4 < str.length() && str[i] == 'S' && str[i+1] == 'l' && str[i+2] == 'a' && str[i+3] == 'v' && str[i+4] == 'a'){
            Slava += 1;
        }
        if( i+5 < str.length() && str[i] == 'N' && str[i+1] == 'i' && str[i+2] == 'k' && str[i+3] == 'i' && str[i+4] == 't' && str[i+5] == 'a'){
            Nikita += 1;
        }
        if( i+2 < str.length() && str[i] == 'A' && str[i+1] == 'n' && str[i+2] == 'n' ){
            Ann += 1;
        }

    }

    if(Danial + Olya + Slava + Ann + Nikita == 1){
        cout << "YES";
    }else cout << "NO";

}