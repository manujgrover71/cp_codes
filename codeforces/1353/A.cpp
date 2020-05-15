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
    int n, m;
    cin >> n >> m;
    if(n == 1){
        cout << 0 << '\n';
    }else if(n == 2){
        cout << m << '\n';
    }else{
        cout << (2*m) << '\n';
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