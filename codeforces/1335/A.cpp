#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long

void solve(){
    int n; cin >> n;
    cout << (n-1)/2 << "\n";
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--)
        solve();

}