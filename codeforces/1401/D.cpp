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

const int mxn = 2 * (int) 1e5 + 5;

vll adj[mxn], dis(mxn);
ll n;

void clearAll() {
    dis.clear();
    for(int i = 0; i < mxn; i++) {
        adj[i].clear();
    }
}

ll dfs(ll curr, ll p) {

    ll ans = 1;

    for(auto child : adj[curr]) {

        if(child != p) {
            ll count = dfs(child, curr);
            dis.pb(count * (n - count));
            ans += count;
        }

    }

    return ans;

}

// Check for number of Cases!!
void solve() {
    cin >> n;

    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    ll noOfK;
    cin >> noOfK;

    vll factors;

    for(int i = 0; i < noOfK; i++) {
        ll x; cin >> x;
        factors.pb(x);
    }

    for(int i = noOfK; i < n; i++) {
        factors.pb(1);
    }

    if(noOfK > n-1) {
        ll res = 1;
        sort(all(factors));
        for(int i = noOfK - 1; i >= n-2; i--) {
            res = (res * factors[i]) % mod;
            factors.pop_back();
        }
        factors.pb(res);
    }

    sort(rall(factors));

    // for(auto i : factors) {
    //     cout << i << ' ';
    // }

    // return;

    dfs(1, -1);

    sort(rall(dis));

    ll ans = 0;

    for(int i = 0; i < n-1; i++) {
        ans = (ans + (dis[i] % mod * factors[i] % mod) % mod) % mod;
    }

    cout << ans % mod << '\n';

    clearAll();
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }
}