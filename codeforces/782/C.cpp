#pragma GCC optimize("Ofast")
#pragma GCCtarget("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

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

ll n;
vll adj[mx];
vll ans;
void dfs(ll curr, ll par, ll currCol, ll parCol) {
    
    ans[curr] = currCol;
    
    ll i = 1;
    
    for(auto child : adj[curr]) {
        if(child != par) {
            while(i == currCol || i == parCol) i++;
            dfs(child, curr, i++, currCol);
        }
    }
    
} 

// Check for number of Cases!!
void solve() {
    cin >> n;
    
    vll in(n+1, 0);
    ans = vll(n+1, 0);
    
    ll maxIn = 0;
    
    for(int i = 0; i < n-1; i++) {
        ll a, b; cin >> a >> b;
        
        adj[a].pb(b);
        adj[b].pb(a);
        in[a]++;
        in[b]++;
        
        maxIn = max({maxIn, in[a], in[b]});
    }
    maxIn++;
    
    dfs(1, -1, 1, 0);
    cout << maxIn << '\n';
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
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