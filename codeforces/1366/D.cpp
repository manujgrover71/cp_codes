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

vll spf(1e7, 0), isPrime(1e7, true);

void sieve(){
    isPrime[0] = isPrime[1] = false;
    
    for(ll i = 2; i <= 1e7; i++){
        if(isPrime[i]){
            spf[i] = i;
            for(ll j = i*i; j <= 1e7; j += i){
                isPrime[j] = false;
                spf[j] = i;
            }
        }
    }
}

void solve(){
    vector< pair<ll, ll> > ans;
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        ll a; cin >> a;

        ll p = spf[a], x = a;
        
        ll d1 = 1;
        while(x%p == 0){
            x /= p;
            d1 *= p;
        }

        ll d2 = a / d1;

        if(d1 > 1 && d2 > 1 && __gcd(d1, d2)){
            ans.pb({d1, d2});
        }else ans.pb({-1, -1});
    }

    for(auto i : ans){
        cout << i.first << ' ';
    }
    cout << '\n';
    for(auto i : ans){
        cout << i.second << ' ';
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    solve();

}