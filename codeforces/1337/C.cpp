#include <algorithm>
#include <iostream>
#include <climits>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;

template <typename T> istream &operator>>
(istream &is, vector<T> &vec) 
{   for (auto &v : vec) is >> v; return is; }

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define ll long long
#define mod 1000000007
#define nod 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pb push_back


// D R U L
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

const int mx = 2e5 + 5;
const int INF = mod;

ll power(ll x, ll y){
    ll res = 1;
    while(y > 0){
        if(y & 1) res = (res * x) % nod;
        y >>= 1;
        x = (x * x) % nod;
    }
    return (res % nod);
}

ll n, k;
vll adj[mx];
vll depth(mx), sz(mx);
vll ans;

ll dfs(ll curr, ll par, ll d = 1) {
    
    depth[curr] = d;
    sz[curr] = 1;
    
    for(auto child : adj[curr]) {
        if(child != par) {
            sz[curr] += dfs(child, curr, d + 1);
        }
    }
    
    ans[curr] = sz[curr] - depth[curr];
    
    return sz[curr];
}

// Check for number of Cases!!
void solve() {
    cin >> n >> k;
    
    for(int i = 0; i < n-1; i++) {
        ll a, b;
        cin >> a >> b;
        
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    ans = vll(n + 1);
    
    ans[0] = -INF;
    
    dfs(1, -1);    
    
    sort(rall(ans));
    
    ll res = 0;
    
    for(int i = 0; i < n - k; i++) {
        res += ans[i];
    }
    
    cout << res << '\n';
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    freopen("/ATOMCODES/err_output.txt", "w", stderr);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }
}