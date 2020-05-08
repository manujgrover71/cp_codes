#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define ll long long

int solve(){
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    bool check = false;

    if(a1 == a2){
        if((b1 + b2) == a1) return true;
        // else cout << "NO\n";
    }
    if(a1 == b2){
        if((a2 + b1) == a1) return true;
        // else cout << "NO\n";
    }
    if(b1 == a2){
        if((a1 + b2) == b1) return true;
        // else cout << "NO\n";
    }
    if(b1 == b2){
        if((a1 + a2) == b1) return true;
        // else cout << "NO\n";
    }

    return false;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        if(solve()){
            cout << "YES\n";
        }else cout << "NO\n";
    }
}