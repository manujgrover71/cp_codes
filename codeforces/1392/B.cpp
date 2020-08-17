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
    ll n, k; cin >> n >> k;

    ll _max = INT_MIN, _min = INT_MAX;

    ll arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];

        _max = max(_max, arr[i]);
        _min = min(_min, arr[i]);
    }

    for(int i = 0; i < n; i++) {
        arr[i] = (_max - arr[i]);
    }

    if(k & 1) {
        for(int i = 0; i < n; i++) {
            cout << arr[i] << ' ';  
        }
    }else {

        for(int i = 0; i < n; i++) {
            cout << (_max - _min) - arr[i] << ' ';
        }
    }
    cout << '\n';

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