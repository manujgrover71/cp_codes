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

ll power(int x, ll y){
    ll res = 1;
    while(y > 0){
        if(y & 1) res = ((res % mod) * (x % mod)) % mod;
        y >>= 1;
        x = x % mod;
    }
    return res;
}

void solve() {
    ll n;
    cin >> n;

    ll fac = 1, pow = 1;

    for(int i = 2; i <= n; i++) {
        fac = fac * i % mod;
        pow = pow * 2 % mod;
    }

    cout << (fac - pow + mod) % mod << '\n';

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }

}