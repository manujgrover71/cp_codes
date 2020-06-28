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
    ll n, k;
    cin >> n >> k;
    ll arr[n];
    map<ll, ll> mp;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] % k != 0) {
            mp[arr[i] % k]++;
        }
    }

    if(mp.empty()) {
        cout << "0\n";
        return;
    }

    ll max = 0, any = 0;
    for(auto i : mp) {
        if(i.second >= max) {
            if(i.second > max) any = i.first;
            else if(i.first <= any) any = i.first;
            max = i.second;
        }
    }

    ll ans =  k * (max - 1) + k - any;
    cout << ans+1 << '\n';

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; 
    cin >> t;
    // t = 1;
    while(t--){
        solve();
    }

}