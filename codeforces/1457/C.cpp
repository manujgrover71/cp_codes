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
	ll n, p, k;
	cin >> n >> p >> k;
	
	string str; cin >> str;
	
	ll x, y; cin >> x >> y;
	
	vll arr(n+1, 0);
	
	for(int i = n - 1; i >= 0; i--) {
		if(i + k <= n-1) {
			arr[i] = (str[i] == '0') + arr[i + k];
		}else {
			arr[i] = (str[i] == '0');
		}
	}
	
	// for(int i = 0; i < n; i++) {
	// 	cout << arr[i] << ' ';
	// }
	// return;
	
	
	ll ans = INF;
	
	for(int i = p-1; i < n; i++) {
		ll curr = ((i - p + 1) * y) + (x * arr[i]);
		ans = min(ans, curr);
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