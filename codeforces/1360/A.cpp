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
    int a, b;
    cin >> a >> b;
    if(a == b){
        cout << (4*a*a) << '\n';
    }else{
        int _min = min(a, b);
        int _max = max(a,b);

        _max = max(_max, 2*_min);

        cout <<  (_max * _max) << '\n';
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