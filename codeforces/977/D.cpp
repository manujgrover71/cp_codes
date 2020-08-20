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
#define rall(x) (x).rbegin(),(x).rend()
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

// Check for number of Cases!!

void recur(ll x, vll ref, map<ll, ll> mp, ll count, ll n) {

    if(count == n) {
        for(int i = 0; i < ref.size(); i++) {
            cout << ref[i] << ' ';
        }
        exit(0);
    }

    if(mp[x * 2]) {
        mp[x*2]--;
        ref.pb(x*2);
        recur(x*2, ref, mp, ++count, n);
    }

    if(x % 3 == 0 && mp[x / 3]) {
        mp[x/3]--;
        ref.pb(x/3);
        recur(x / 3, ref, mp, ++count, n);
    }

}


void solve() {
    int n; cin >> n;

    ll arr[n];

    map<ll, ll> mp;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]]++;
    }

    for(int i = 0; i < n; i++) {
        vector<ll> ref;
        ref.pb(arr[i]);
        ll count = 1;
        recur(arr[i], ref, mp, count, n);
        ref.clear();
    }

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }
}