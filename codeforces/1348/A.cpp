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
    ll a = 0, b = 0;
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        if(i < n/2 || i == n)
            a += pow(2, i);
        else 
            b += pow(2, i);
    }

    cout << abs(b - a) << '\n';
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