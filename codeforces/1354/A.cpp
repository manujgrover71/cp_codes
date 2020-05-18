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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if(b >= a){
        cout << b << '\n';
        return;
    }else{
        a -= b;
        ll temp = (c - d);
        if(temp < 1) {
            cout << "-1\n";
            return;
        }
        cout << b +  (ll)(c * ceil((double)a / temp)) << '\n';
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