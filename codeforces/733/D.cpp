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


struct edge{
	ll a, b, c;
};


// Check for number of Cases!!
void solve() {
	ll n; cin >> n;
	vector<edge> arr(n);

	ll ans = -1;

	map<pair<ll, ll>, pair<ll, ll>> mp;

	ll a = -1, b = -1;

	for(int i = 0; i < n; i++) {
		cin >> arr[i].a >> arr[i].b >> arr[i].c;
		if(ans < min({arr[i].a, arr[i].b, arr[i].c})) {
			a = i, b = -1;
			ans = min({arr[i].a, arr[i].b, arr[i].c});
		}

		if(ans < min({mp[{arr[i].a, arr[i].b}].first + arr[i].c, arr[i].a, arr[i].b})) {
			ans = min({mp[{arr[i].a, arr[i].b}].first + arr[i].c, arr[i].a, arr[i].b});
			a = i, b = mp[{arr[i].a, arr[i].b}].second;
		}

		if(ans < min({mp[{arr[i].b, arr[i].a}].first + arr[i].c, arr[i].a, arr[i].b})) {
			ans = min({mp[{arr[i].b, arr[i].a}].first + arr[i].c, arr[i].a, arr[i].b});
			a = i, b = mp[{arr[i].b, arr[i].a}].second;
		}

		if(ans < min({mp[{arr[i].a, arr[i].c}].first + arr[i].b, arr[i].a, arr[i].c})) {
			ans = min({mp[{arr[i].a, arr[i].c}].first + arr[i].b, arr[i].a, arr[i].c});
			a = i, b = mp[{arr[i].a, arr[i].c}].second;
		}
		
		if(ans < min({mp[{arr[i].c, arr[i].a}].first + arr[i].b, arr[i].a, arr[i].c })) {
			ans = min({mp[{arr[i].c, arr[i].a}].first + arr[i].b, arr[i].a, arr[i].c });
			a = i, b = mp[{arr[i].c, arr[i].a}].second;
		}

		if(ans < min({mp[{arr[i].b, arr[i].c}].first + arr[i].a, arr[i].b, arr[i].c })) {
			ans = min({mp[{arr[i].b, arr[i].c}].first + arr[i].a, arr[i].b, arr[i].c });
			a = i, b = mp[{arr[i].b, arr[i].c}].second;
		}

		if(ans < min({mp[{arr[i].c, arr[i].b}].first + arr[i].a, arr[i].b, arr[i].c })) {
			ans = min({mp[{arr[i].c, arr[i].b}].first + arr[i].a, arr[i].b, arr[i].c });
			a = i, b = mp[{arr[i].c, arr[i].b}].second;
		}

		if(mp[{arr[i].a, arr[i].b}].first < arr[i].c) {
			mp[{arr[i].a, arr[i].b}].first = arr[i].c;
			mp[{arr[i].a, arr[i].b}].second = i;
		}

		if(mp[{arr[i].b, arr[i].a}].first < arr[i].c) {
			mp[{arr[i].b, arr[i].a}].first = arr[i].c;
			mp[{arr[i].b, arr[i].a}].second = i;
		}

		if(mp[{arr[i].a, arr[i].c}].first < arr[i].b) {
			mp[{arr[i].a, arr[i].c}].first = arr[i].b;
			mp[{arr[i].a, arr[i].c}].second = i;
		}

		if(mp[{arr[i].c, arr[i].a}].first < arr[i].b) {
			mp[{arr[i].c, arr[i].a}].first = arr[i].b;
			mp[{arr[i].c, arr[i].a}].second = i;
		}

		if(mp[{arr[i].b, arr[i].c}].first < arr[i].a) {
			mp[{arr[i].b, arr[i].c}].first = arr[i].a;
			mp[{arr[i].b, arr[i].c}].second = i;
		}

		if(mp[{arr[i].c, arr[i].b}].first < arr[i].a) {
			mp[{arr[i].c, arr[i].b}].first = arr[i].a;
			mp[{arr[i].c, arr[i].b}].second = i;
		}
	}

	if(b == -1) {
		cout << "1\n" << a+1 << '\n';
	}else {
		cout << "2\n" << a+1 << ' ' << b+1 << '\n';
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