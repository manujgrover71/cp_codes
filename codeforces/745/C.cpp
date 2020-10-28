#include <algorithm>
#include <unordered_set>
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

// ------------------------------------------------

template <typename T> istream &operator>>
(istream &is, vector<T> &vec) 
{   for (auto &v : vec) is >> v; return is; }

template<typename T> 
void dout(string name, T arg) {
    cerr << arg << endl;
}

template<typename T1, typename... T2> 
void dout(string names, T1 arg, T2... args) {
    cerr << arg << " | ";
    dout(names.substr(names.find(',') + 2), args...);
}

#ifndef ONLINE_JUDGE
    #define debug(...) dout(#__VA_ARGS__, __VA_ARGS__)
#else
    #define debug(...) 
#endif

// --------------------------------------------------

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

const int mx = 1e3 + 5;
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


vll adj[mx], vis(mx, false);
unordered_set<ll> gov;
bool anyGov;
ll el = 0;


ll dfs(ll curr) {
    if(vis[curr]) return 0;

    vis[curr] = true;

    el++;
    if(gov.find(curr) != gov.end())
        anyGov = true;

    ll count = adj[curr].size();

    for(auto child : adj[curr]) {
        if(!vis[child]) {
            count += dfs(child);
        }
    }

    return count;
}

// Check for number of Cases!!
void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    while(k--) {
        ll x; cin >> x;
        gov.insert(x);
    }

    while(m--) {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    ll ans = 0;
    ll maxSize = 0;
    vll extras;

    for(int i = 1; i <= n; i++) {
        el = 0;
        anyGov = false;

        ll vertexCount = dfs(i);
        vertexCount /= 2;

        ans += el * (el - 1) / 2 - vertexCount;
        if(anyGov) maxSize = max(maxSize, el);
        else extras.pb(el);
    }

    for(int i = 0; i < extras.size(); i++) {
        ans += extras[i] * maxSize;
        maxSize += extras[i];
    }

    cout << ans;

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