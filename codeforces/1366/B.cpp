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

void solve(){
    ll n, x, m;
    cin >> n >> x >> m;

    ll lRef = x, rRef = x;

    while(m--){
        ll l, r;
        cin >> l >> r;

        if(lRef >=l && lRef <= r && rRef > r){
            lRef = min(l, lRef);
        }

        else if(rRef >= l && rRef <= r && lRef < l) {
            rRef = max(r, rRef);
        }

        else if(lRef >= l && rRef <= r){
            lRef = min(l, lRef);
            rRef = max(r, rRef);
        }
    }

    // cout << lRef << ' ' << rRef << '\n';

    cout << (rRef - lRef + 1) << '\n';
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