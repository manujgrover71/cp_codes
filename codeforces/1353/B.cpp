#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
#define ll long long

void solve(){  
    int n, k; cin >> n >> k;
    int a[n], b[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) cin >> b[i];

    sort(a, a+n);
    sort(b, b+n, greater<int>());
    ll ans = 0;
    for(int i = 0, j = 0; i < n; i++){
        if( k && j < n && a[i] < b[j]){
            a[i] = b[j];
            j++;
            k--;
        }
        ans += a[i];
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