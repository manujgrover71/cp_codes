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
#define rall(x) (x).rbegin(),(x).rend()
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

ll fun(ll x, ll n, ll m) {
    ll res = 0;
    x--;

    for(int i = 1; i <= n; i++) {
        res += min((ll)m, (x/i));
    }

    return res;
}

// Check for number of Cases!!
void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    ll l = 1, r = (1ll * n * m) + 1;

    while(l < r) {
        ll mid = l + (r - l) / 2;

        if(fun(mid, n, m) < k) {
            l = mid + 1;
        }else r = mid;
    }

    cout << l - 1;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }
}