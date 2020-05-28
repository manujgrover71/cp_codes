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

bool check(ll v, ll n, ll k){
    ll ans = 0;
    ll d = 1;
    while (true){
        ans += v / d;
        if(v/d == 0) break;
        d *= k;
    }

    return ans >= n;
}

void solve(){
    ll n, k; cin >> n >> k;
    ll start = 1, end = n;
    while(start != end){
        ll mid = (start + end) / 2;
        if(check(mid, n, k)){
            end = mid;
        }else start = mid + 1;
    }

    cout << start;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

}