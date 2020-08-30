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
    int n; cin >> n;
    int arr[3];
    
    for(int i = 0; i < 3; i++) {
        cin >> arr[i];
    }

    int dp[n+1];
    fill_n(dp, n+1, 0);

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            if(i - arr[j] >= 0) {
                if(i == arr[j])
                    dp[i] = max(dp[i], 1);
                else if(dp[i - arr[j]] != 0) 
                    dp[i] = max(dp[i], dp[i-arr[j]] + 1);
            }
        }
    }
    
    cout << dp[n];

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