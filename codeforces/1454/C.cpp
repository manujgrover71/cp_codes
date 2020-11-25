
#include <unordered_map>
#include <unordered_set>
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



// Check for number of Cases!!
void solve() {
	ll n; cin >> n;
	vll arr(n+1);
	
	bool isSame = true;
	
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
		if(i > 1) {
			if(arr[i-1] != arr[i]) isSame = false;
		}
	}
	
	if(isSame) {
		cout << "0\n";
		return;
	}
	
	unordered_map<ll, pair<ll, ll>> mp;
	ll ans = INF;
	
	for(int i = 1; i <= n; i++) {
		if(i != 1 && mp[arr[i]].first == 0) mp[arr[i]].second++;
		else if(i - mp[arr[i]].first != 1) mp[arr[i]].second++;
		
		mp[arr[i]].first = i;
	}
	
	
	for(auto i : mp) {
		if(i.first != arr[n]) ans = min(ans, i.second.second + 1);
		else ans = min(ans, i.second.second);
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