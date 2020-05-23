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
    int n; cin >> n;
    vector<int> v;
    for(int i = 2; i <= n; i+=2){
        v.emplace_back(i);
    }

    for(int i = 1; i <= n; i+=2){
        v.emplace_back(i);
    }

    for(int i = 2; i <= n; i+=2){
        v.emplace_back(i);
    }

    cout << v.size() << '\n';
    for(auto i : v) cout << i << ' ';
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int t; cin >> t;
    // while(t--){
        solve();
    // }
}