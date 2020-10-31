#include <algorithm>
#include <iostream>
#include <unordered_map>
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

const int mx = 1e6 + 5;
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
                if(sz[x] < sz[y])
                    swap(x, y);

                parent[y] = x;
                sz[x] += sz[y];
            }
        }
};

// Check for number of Cases!!
void solve() {
    ll n, k;
    cin >> n >> k;

    DSU dsu(n);

    string str; cin >> str;

    vll vis(n, false);

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            for(int j = i; j < n; j += k) {
                dsu.union_set(i, j);
                vis[j] = true;
            }
        }
    }

    for(int i = 0, j = n-1; i < j; i++, j--) {
        dsu.union_set(i, j);
    }

    vector<vector<ll>> freq(n + 1, vector<ll> (26, 0));
    vector<pair<ll, ll>> ref(n, {0, 0});

    for(int i = 0; i < n; i++) {
        ll x = dsu.find_parent(i);
        freq[x][str[i] - 'a']++;
        ll currMax = max(ref[x].first, freq[x][str[i]-'a']);
        ll newSize = ref[x].second + 1;

        ref[x] = {currMax, newSize};
    }

    ll ans = 0;

    for(auto i : ref) {
        debug(i.first, i.second);
        ans += (i.second - i.first);
    }

    cout << ans << '\n';
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
    cin >> t;
    while(t--) {
      solve();
    }
}