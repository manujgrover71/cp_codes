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

ll n;

bool isSafe(ll x, ll y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

// Check for number of Cases!!
void solve() {
	cin >> n;
	
	string arr[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(arr[i][j] == '.') {
				arr[i][j] = '#';
				ll count = 1;
				if(isSafe(i+1, j) && arr[i+1][j] == '.') {
					arr[i+1][j] = '#';
					count++;
				}
				if(isSafe(i+1, j-1) && arr[i+1][j-1] == '.') {
					arr[i+1][j-1] = '#';
					count++;
				}
				if(isSafe(i+1, j+1) && arr[i+1][j+1] == '.') {
					arr[i+1][j+1] = '#';
					count++;
				}
				if(isSafe(i+2, j) && arr[i+2][j] == '.') {
					arr[i+2][j] = '#';
					count++;
				}
				if(count != 5) {
					cout << "NO";
					return;
				}
			}
		}
	}
	
	cout << "YES";
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