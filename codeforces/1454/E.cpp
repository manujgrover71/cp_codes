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

vll adj[mx];
vector<bool> vis(mx);
vll cycleEdges;

bool done = false;

void dfs(ll curr, ll par, vector<ll>& callStack) {

	if(done) return;

	if(vis[curr]) {
		ll temp = curr;
		
		cycleEdges.pb(temp);
		
		while(callStack.back() != temp) {
			cycleEdges.pb(callStack.back());
			callStack.pop_back();
		}
		
		done = true;
		return;
	}
	
	vis[curr] = true;
	
	callStack.pb(curr);
	
	for(auto child : adj[curr]) {
		
		if(done) return;
		
		if(child != par) {
			dfs(child, curr, callStack);
		}
	}
	
	if(done) return;
	callStack.pop_back();	
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
		
		ll getSize(ll x) {
			return sz[x];
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
	ll n; cin >> n;
	
	vector<pair<ll, ll>> edges;
	
	for(int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		
		edges.pb({a, b});
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	vll callStack;
	
	dfs(1, -1, callStack);
	
	set<pair<ll, ll>> cEdges;
	
	for(int i = 0; i < cycleEdges.size(); i++) {
		ll a = cycleEdges[i], b = cycleEdges[(i+1)%cycleEdges.size()];
		
		cEdges.insert({a, b});
		cEdges.insert({b, a});
	}
	
	DSU dsu(n);
	
	for(auto i : edges) {
		if(cEdges.find({i.first, i.second}) == cEdges.end())
			dsu.union_set(i.first, i.second);
	}
	
	ll ans = n * (n - 1);
	
	for(int i = 1; i <= n; i++) {
		if(dsu.find_parent(i) == i) {
			ll sz = dsu.getSize(i);
			ans -= sz * (sz - 1) / 2;
		}
	}
	
	cout << ans << '\n';
	
	for(int i = 0; i <= n; i++) {
		adj[i].clear();
		vis[i] = false;
	}
	cycleEdges.clear();
	callStack.clear();
	done = false;
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