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
    int n, k; cin >> n >> k;
    ll arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    ll w[k];
    for(int i = 0; i < k; i++) cin >> w[i];
    sort(w, w+k);

    ll ans = 0;
    int start = 0, end = n-1, j = 0;
    ll countOne= 0;
    for(int i = 0; i < k; i++) {
        if(w[i] == 1) countOne++;
        else break;
    }
    ll temp = k;
    while(countOne--) {
        ans += arr[end] * 2;
        // cout << arr[end] << '\n';
        end--;
        k--;
    }

    sort(w, w+temp, greater<int>());

    while(k--) {
        ans += arr[end] + arr[start];
        // cout << arr[start] << ' ' << arr[end] << '\n';
        end--;
        w[j]--;
        start += w[j];

        j++;
    }
    cout << ans << '\n';

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