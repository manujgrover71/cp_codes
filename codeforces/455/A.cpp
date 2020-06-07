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
#define FOR(i, n, c) for(int (i) = 0; (i) < (n); (i) += (c))
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

ll freq[100005];
ll dp[100005];

void solve(){
    int n; cin >> n;
    FOR(i, n, 1){
        int a; cin >> a;
        freq[a]++;
    }

    dp[0] = 0;
    dp[1] = freq[1];

    // cout << freq[1];

    FOR(i, 100001, 1){
        if(i > 1){
            if(freq[i]) 
                dp[i] = dp[i-2] + (i * 1ll * freq[i]);
            dp[i] = max(dp[i], dp[i-1]);
        }
        
    }
    
    cout << dp[100000];

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