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

const int mx = 1e5 + 5;
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


ll nodes;
vll adj[mx], vis(mx, false);
map<ll, bool> A, B;

void dfs(ll curr, ll c) {
    vis[curr] = true;

    if(c) {
        A[curr] = true;
    }else {
        B[curr] = true;
    }

    for(auto child : adj[curr]) {
        if(!vis[child]) {
            dfs(child, c ^ 1);
        }
    }
}

// Check for number of Cases!!
void solve() {
    ll edges;
    cin >> nodes >> edges;

    vector<pair<ll, ll>> input;

    while(edges--) {
        ll a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
        input.pb({a, b});
    }    

    for(int i = 1; i <= nodes; i++) {
        if(!vis[i]) {
            dfs(i, 0);
        }
    }

    for(auto i : input) {
        if(A[i.first] && A[i.second] || B[i.second] && B[i.first]) {
            cout << "-1\n";
            return;
        }
    }

    vll ans1, ans2;
    for(auto i : A) {
        if(i.second)
            ans1.pb(i.first);
    }
    for(auto i : B) {
        if(i.second)
            ans2.pb(i.first);
    }

    cout << ans1.size() << '\n';
    for(auto i : ans1) {
        cout << i << ' ';
    }

    cout << '\n' << ans2.size() << '\n';
    for(auto i : ans2) {
        cout << i << ' ';
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