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
    ll a, b;
    cin >> a >> b;

    if(a > b) swap(a, b);

    if(a == b) cout << "0\n";
    else if(b & 1) cout << "-1\n";
    else {
        ll counter = 0;
        if(a < b){
            while(a < b){
                a <<= 1;
                counter++;
            }
        }
        if(a != b) cout << "-1\n";
        else {

            ll ans = 0;
            ans += counter / 3;
            counter %= 3;
            ans += counter / 2;
            counter %= 2;
            ans += counter / 1;

            cout << ans << '\n';
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