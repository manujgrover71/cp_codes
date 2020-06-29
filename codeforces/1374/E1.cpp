#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define all(x) (x).begin(),(x).end()
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

vector<pair<ll, pair<int, int>>> vx;

// ll help(vector<pair<ll, pair<int, int>>> vx, ll k, ll i,ll n) {
//     if(!vx[i].second.first && !vx[i].second.second) {
//         return -1;
//     }
 
//     if(i == n) return 0;

//     if(help(vx, k, i+1, n) != -1) {
//         return vx[i].first + help(vx, k, i+1, n);
//     }

//     if()
// }

void solve() {
    int n, r; cin >> n >> r;
    vector< ll > oneone, onezero, zeroone;
    for(int i = 0; i < n; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        if(a && b) oneone.pb(t);
        else if(a) onezero.pb(t);
        else if(b) zeroone.pb(t);
    }

    sort(all(onezero));
    sort(all(zeroone));
    // sort(all(oneone));

    for(int i = 0; i < min(onezero.size(), zeroone.size()); i++) {
        oneone.pb(onezero[i] + zeroone[i]);
    }

    if(oneone.size() < r) {
        cout << "-1\n";
        return;
    }
    
    sort(all(oneone));
    ll ans = 0;
    for(int i = 0; i < r; i++) {
        ans += oneone[i];
    }

    cout << ans << '\n';
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }

}