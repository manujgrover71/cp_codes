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
    ll n, m;
    cin >> n >> m;
    ll t[n], l[n], h[n];
    ll maxMin = m, maxMax = m, last = 0;
    for(int i = 0; i < n; i++){
        cin >> t[i] >> l[i] >> h[i];
    }

    for(int i = 0; i < n; i++){
        maxMin -= t[i] - last;
        maxMax += t[i] - last;

        if(h[i] < maxMin || l[i] > maxMax){
            cout << "NO\n";
            return;
        }

        maxMin = max(maxMin, l[i]);
        maxMax = min(maxMax, h[i]);
        last = t[i];
    }

    cout << "YES\n";
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