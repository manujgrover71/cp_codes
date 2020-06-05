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
#define pb push_back

ll power(ll x, ll y){
    ll res = 1;
    while(y > 0){
        if(y & 1) res = res * x;
        y >>= 1;
        x *= x;
    }
    return res;
}


int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    map<ll, ll> mp;
    mp[1] = 1;
    for(ll i = 2; i <= 1e18 + 20; i *= 2){
        mp[i] = mp[i/2] * 2 + 1;
    }

    while(t--){
        ll a; cin >> a;
        ll ans = 0;
        ll i = 0;
        while(a > 0){
            if(a % 2){
                ans += mp[power(2, i)];
            }
            i++;
            a /= 2;
        }
        cout << ans << '\n';
    }

}