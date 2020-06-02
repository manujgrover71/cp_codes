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

void solve(){
    int n, p, k;
    cin >> n >> p >> k;
    int arr[n];

    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    int dp[n+1] = {0};
    ll ans = 0;
    for(int i = 0; i < k-1; i++){
        if(i) dp[i] = arr[i] + dp[i-1];
        else dp[i] = arr[i];

        if(dp[i] <= p) ans = i+1;
    }

    for(int i = k - 1; i < n; i++){
        if(i - k > -1)
            dp[i] = arr[i] + dp[i-k];
        else dp[i] = arr[i];
        if(dp[i] <= p) ans = i+1;
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