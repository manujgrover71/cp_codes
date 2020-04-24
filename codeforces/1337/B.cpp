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
    int hel, n, m;
    cin >> hel >> n >> m;
    ll m_left = 10 * m;
    while(n-- && (hel/2 + 10 < hel)){
        hel = (hel/2) + 10; 
        if(hel <= 0) {
            cout << "YES\n";
            return;
        }
    }
    if(hel - m_left <= 0) cout << "YES\n";
    else cout << "NO\n";
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