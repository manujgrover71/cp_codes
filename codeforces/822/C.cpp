#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

struct type {
	ll l, r, cost, t;
	type(ll l, ll r, ll t, ll cost) {
		this->l = l;
		this->r = r;
		this->cost = cost;
		this->t = t;
	}
};

// Check for number of Cases!!
void solve() {
	ll n, x;
	cin >> n >> x;
	
	vector<type> arr;
	
	for(int i = 0; i < n; i++) {
		ll l, r, c; cin >> l >> r >> c;
		arr.push_back(type(l, r, 0, c));
		arr.push_back(type(r, l, 1, c));
	}
	
	sort(all(arr), [&] (const type &a, const type &b) {
		if(a.l != b.l) return a.l < b.l;
		if(a.t != b.t) return a.t < b.t;
		return a.r < b.r;
	});
	
	vll ref(x+1, INF);
	
	ll ans = LLONG_MAX;
	
	for(ll i = 0; i < arr.size(); i++) {
		if(arr[i].t == 0) {
			ll l = arr[i].l, r = arr[i].r, c = arr[i].cost;
			
			ll days = r - l + 1;
			ll req = x - days;
			
			if(req > 0 && ref[req] != INF) {
				ans = min(ans, c + ref[req]);
			}
		}else {
			ll l = arr[i].r, r = arr[i].l, c = arr[i].cost;
			ll days = r - l + 1;
			if(days >= x) continue;
			ref[days] = min(ref[days], c);
		}
	}
	
	if(ans == LLONG_MAX) ans = -1;
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
	// cin >> t;
	while(t--) {
	  solve();
	}
}