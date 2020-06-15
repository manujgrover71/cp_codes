#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

#define ll long long
#define mod 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pb push_back

ll power(int x, unsigned int y){
    ll res = 1;
    while(y > 0){
        if(y & 1) res = res * x;
        y >>= 1;
        x *= x;
    }
    return res;
}

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    x++, y++;

    ll h1 = 0, h2 = 0;

    h1 = (n - x) * m;
    if(x-1 > 0)
        h2 = (x - 1) * m;
    
    ll ans1 = max(h1, h2);

    ll v1 = 0, v2 = 0;

    v1 = (m - y) * n;
    if(m - 1 > 0)
        v2 = (y - 1) * n;

    ll ans2 = max(v1, v2);
    cout << max(ans1, ans2) << '\n';
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