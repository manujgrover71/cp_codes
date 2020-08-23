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
void solve() {
    ll n;
    cin >> n;

    ll arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ref[3];
    fill_n(ref, 3, 0);

    for(int i = 0; i < n; i++) {
        ref[arr[i] % 3]++;
    }

    ll ans = ref[0];
    ll x = min(ref[1], ref[2]);
    ans += x;
    ref[1] -= x;
    ref[2] -= x;

    ans += ref[1]/ 3;
    ans += ref[2] / 3;

    cout << ans << '\n';

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }
}