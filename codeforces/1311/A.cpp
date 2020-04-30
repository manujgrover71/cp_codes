#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define ll long long

void solve(){
    ll a, b; cin >> a >> b;
    if(a == b){
        cout << "0\n";
        return;
    }
    if(a > b){
        int x = a - b;
        if(x & 1) cout << "2\n";
        else cout << "1\n";
    }else{
        int x = b - a;
        if(x & 1) cout << "1\n";
        else cout << "2\n";
    }
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
        solve();
    }
}