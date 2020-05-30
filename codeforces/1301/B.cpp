#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define ll long long
#define mod 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pb(x) push_back(x)

ll power(int x, unsigned int y){
    ll res = 1;
    while(y > 0){
        if(y & 1) res = res * x;
        y >>= 1;
        x *= x;
    }
    return res;
}

void solve(){
    int n;
	cin >> n;
    ll arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

    ll _max = 0, _min = 1e9;

	for(int i = 0; i < n; i++){
		if(i > 0 && arr[i] == -1 && arr[i - 1] != -1){
			_min = min(_min , arr[i-1]);
            _max = max(_max , arr[i-1]);
        }
		if(i < n - 1 && arr[i] == -1 && arr[i + 1] != -1){
			_min = min(_min , arr[i+1]);
            _max = max(_max , arr[i+1]);
        }
	}
	int res = (_max + _min) / 2;
	ll ans = 0;
	for(int i=0;i<n;i++){
		if(arr[i] == -1)
			arr[i] = res;
		if(i)
			ans = max(ans,abs(arr[i] - arr[i - 1]));
	}
	cout << ans << ' ' << res << '\n';
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        solve();
    }

}