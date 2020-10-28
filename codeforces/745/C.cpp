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

vll adj[mx];
map<ll, ll> gov;
vll vis(mx,false);

class DSU {

    private:
        vector<ll> parent;
        vector<ll> sz;

    public:

        DSU(ll size) {
            parent.resize(size+1);
            sz.resize(size+1);

            for(int i = 1; i <= size; i++) {
                make_set(i);
            }
        }

        ll getSize(ll x) {
            ll p = this->find_parent(x);
            return sz[this->find_parent(x)];
        }

        void setParentSize(ll x) {
            sz[this->find_parent(x)] = 0;
        }

        void make_set(ll curr) {
            parent[curr] = curr;
            sz[curr] = 1;
        }

        ll find_parent(ll curr) {
            return (parent[curr] == curr) ? curr : find_parent(parent[curr]);
        }

        void union_set(ll x, ll y) {
            x = find_parent(x);
            y = find_parent(y);

            if(x != y) {
                if(gov.find(x) != gov.end()) {
                    sz[x] += sz[y];
                    parent[y] = x;
                }else {
                    sz[y] += sz[x];
                    parent[x] = y;
                }
            }
        }
};

ll dfs(ll curr) {

    if(vis[curr]) return 0;

    vis[curr] = true;

    ll size = adj[curr].size();

    for(auto child : adj[curr]) {
        if(!vis[child])
            size += dfs(child);
    }

    return size;
}

// Check for number of Cases!!
void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    DSU dsu(n);

    for(int i = 0; i < k; i++) {
        ll x; cin >> x;
        gov[x] = 0;
    }

    while(m--) {
        ll a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
        dsu.union_set(a, b);
    }

    vll ref;

    ll maxSize = 0, ans = 0;

    vll extras;

    for(int i = 1; i <= n; i++) {
        if(gov.find(dsu.find_parent(i)) != gov.end()) {
            ll currSize = dsu.getSize(dsu.find_parent(i));
            dsu.setParentSize(i);
            ll totalSize = dfs(i);
            totalSize /= 2;
            ans += (currSize * (currSize - 1)) / 2 - totalSize;
            if(currSize > maxSize) {
                maxSize = currSize;
            }
        }else {
            ll currSize = dsu.getSize(i);
            ref.pb(currSize);
            ll totalSize = dfs(i);
            totalSize /= 2;
            ans += currSize * (currSize - 1) / 2 - totalSize;
            dsu.setParentSize(i);
        }
    }

    for(int i = 0; i < ref.size(); i++) {
        ans += ref[i] * maxSize;
        maxSize += ref[i];
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