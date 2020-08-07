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
#define vi vector<ll>
#define vll vector<ll>
#define pb push_back

ll power(ll x, unsigned ll y){
    ll res = 1;
    while(y > 0){
        if(y & 1) res = res * x;
        y >>= 1;
        x *= x;
    }
    return res;
}

struct cmp {
    bool operator() (pair<ll, ll> a, pair<ll, ll> b) {
        return ((a.first - a.first / 2) * a.second) <= ((b.first - b.first/2) * b.second);
    }
};

vector<pair<ll,ll>> adj[(ll)1e5 + 1];
priority_queue<pair<ll, ll>, vector<pair<ll,ll> >, cmp> pq;
ll sum = 0;

ll dfs(ll v, ll parent) {
    ll ans = 0;
    for(auto child : adj[v]) {
        if(child.first == parent) continue;
        ll temp = dfs(child.first, v);
        pq.push({child.second, temp});
        sum += (temp) * child.second;
        ans += temp;
    }
    if(!ans) ans = 1;
    return ans;
}

void clearAll() {
    for(ll i = 0; i < (ll)1e5 + 1; i++)
        adj[i].clear();
    pq = priority_queue<pair<ll, ll>, vector<pair<ll,ll> >, cmp> ();
    sum = 0;
}

void solve() {

    ll nodes, total;
    cin >> nodes >> total;

    for(ll i = 0; i < nodes-1; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }

    dfs(1, 0);

    ll ans = 0;

    while(sum > total) {
        auto f = pq.top();
        pq.pop();
        ans++;
        sum -= f.first * f.second;
        f.first /= 2;
        if(f.first) {
            pq.push({f.first, f.second});
            sum += f.first * f.second;
        }
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

    ll t; cin >> t;
    while(t--){
        solve();
        clearAll();
    }

}