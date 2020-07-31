#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define ll long long
#define mod 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pb push_back

ll power(int x, unsigned int y){
    ll res = 1;
    while(y > 0){
        if(y & 1) res = res * x;
        y >>= 1;
        x *= x;
    }
    return res;
}

void solve() {
    ll n; cin >> n;

    vll arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(all(arr));

    ll ans = arr[0] * arr[n-1];

    vll ref;

    for(ll i = 2; i*i*1ll <= ans; i++) {
        if(ans % i == 0) {
            ref.pb(i);
            if(ans/i != i) 
                ref.pb(ans/i);
        }
    }

    sort(all(ref));

    if(ref == arr)
        cout << ans << '\n';
    else cout << "-1\n";
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