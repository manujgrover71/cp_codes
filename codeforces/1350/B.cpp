#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define ll long long

void solve(){
    ll n; cin >> n;
    
    ll arr[n+1];
    ll dp[n+1];
    
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i] = 1;
    }
    
    
    ll ans = 1;
    
    for(int i = 2; i <= n; i++){
        ll ref = 0;
        for(int j = 1; j*j <= i; j++){
            if(i % j == 0){
                ll div1 = j, div2 = i / j;
                if(arr[div1] < arr[i]){
                    ref = max(dp[div1], (ll)ref);
                }
                
                if(arr[div2] < arr[i]){
                    ref = max(dp[div2], (ll)ref);
                }
            }
        }

        dp[i] += ref;
        ans = max((ll)ans, dp[i]);
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