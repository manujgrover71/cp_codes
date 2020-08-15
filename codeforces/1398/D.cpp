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

ll dp[202][202][202];
ll r[202], g[202], b[202];

void solve() {

    int R, G, B;
    cin >> R >> G >> B;

    for(int i = 0; i < R; i++)
        cin >> r[i];
    
    for(int i = 0; i < G; i++)
        cin >> g[i];
    
    for(int i = 0; i < B; i++)
        cin >> b[i];

    sort(r, r + R);
    sort(g, g + G);
    sort(b, b + B);

    for(int i = 0; i <= R; i++) {
        for(int j = 0; j <= G; j++) {
            for(int k = 0; k <= B; k++) {
                if(i && j) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k] + (r[i-1] * g[j-1]));
                }
                if(j && k) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1] + (g[j-1] * b[k-1]));
                }
                if(i && k) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1] + (r[i-1] * b[k-1]));
                }
            }
        }
    }
    
    cout << dp[R][G][B];
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }

}