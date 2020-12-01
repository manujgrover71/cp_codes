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


// Check for number of Cases!!
void solve() {
	ll n, m;
	cin >> n >> m;
	
	vector<pair<ll, ll>> edges;
	vll adj[n+10];	
	vll in(n + 10, 0);
	
	for(int i = 0; i < m; i++) {
		ll t, a, b;
		cin >> t >> a >> b;
		
		if(t) {
			adj[a].pb(b);
			in[b]++;
		}
		edges.pb({a, b});
	}
	
	queue<ll> q;
	
	vll toposort;
	
	for(int i = 1; i <= n; i++) {
		if(in[i] == 0) {
			q.push(i);
			toposort.pb(i);
		}
	}
	
	vll pos(n + 10, 0);
	
	ll p = 0;
	
	while(!q.empty()) {
		ll curr = q.front(); q.pop();
		pos[curr] = p++;
		for(auto child : adj[curr]) {
			in[child]--;
			if(in[child] == 0) {
				q.push(child);
				toposort.pb(child);
			}
		}
	}
	
	if(p != n) {
		cout << "NO\n";
	}else {
		cout << "YES\n";
		
		for(int i = 0; i < edges.size(); i++) {
			if(pos[edges[i].first] > pos[edges[i].second]) {
				swap(edges[i].first, edges[i].second);
			}
			cout << edges[i].first << ' ' << edges[i].second << '\n';
		}
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
	cin >> t;
	while(t--) {
	  solve();
	}
}