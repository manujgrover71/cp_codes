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

    int n; cin >> n;
    string s; cin >> s;

    if(n == 0 || n == 1) {
        cout << 0;
        return 0;
    }

    // rb
    
    int a = 0, b = 0;
    for(int i = 0; i < n; i++){
        if(i & 1){
            if(s[i] != 'b') b++;
        }
        else{
            if(s[i] != 'r') a++;
        } 
    }
    int c = 0, d = 0;
    // br
    for(int i = 0; i < n; i++){
        if(i & 1){
            if(s[i] != 'r') d++;
        }
        else{
            if(s[i] != 'b') c++;
        } 
    }

    cout << min(max(a,b), max(c,d));
}