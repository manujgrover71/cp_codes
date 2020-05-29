#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
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
    ll h, c, t;
		cin >> h >> c >> t;
 
		if (t == h) {
			cout << "1" << "\n";
		} else {
			if (2 * t <= (h + c)) {
				cout << "2" << "\n";
			} else {
 
				ll x = (t - c) / (2 * t - h - c);
				ll y = x + 1;
 
				long double try1 = ((x * h) + (x - 1) * c) / (1.0 * (2 * x - 1));
				long double try2 = ((y * h) + (y - 1) * c) / (1.0 * (2 * y - 1));
 
				long double diff1 = abs(try1 - t);
				long double diff2 = abs(try2 - t);
 
				if (diff1 <= diff2) {
					cout << 2 * x - 1 << "\n";
				} else {
					cout << 2 * y - 1 << "\n";
				}
			}
		}

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