#include <algorithm>
#include <iostream>
#include <unordered_set>
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
#define mod 998244353
#define nod 998244353
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



// Check for number of Cases!!
void solve() {
	ll n, m;
	cin >> n >> m;

	vll arr(n);
	map<ll, ll> mp;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		mp[arr[i]] = i;
	}

	unordered_set<ll> st;
	vll brr(m);
	for(int i = 0; i < m; i++) {
		cin >> brr[i];
		st.insert(brr[i]);
	}

	ll ans = 1;

	for(int i = 0; i < m; i++) {
		ll pos = mp[brr[i]];
		ll ref = 0;

		if(pos > 0) {
			if(st.find(arr[pos - 1]) == st.end()) {
				ref++;
			}
		}
		if(pos < n-1) {
			if(st.find(arr[pos+1]) == st.end()) {
				ref++;
			}
		}
		st.erase(brr[i]);
		ans = (ans * ref) % mod;
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