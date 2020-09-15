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

// D R U L
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

const int mx = 1e6 + 5;
const int INF = mod;

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
    ll n; cin >> n;

    vector<ll> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll dp[n+5][2];

    dp[0][0] = arr[0];
    dp[0][1] = INF;
    dp[1][0] = arr[0] + arr[1];
    dp[1][1] = arr[0];

    for(int i = 2; i < n; i++) {
        dp[i][0] = min(dp[i-1][1] + arr[i], dp[i-2][1] + arr[i-1] + arr[i]);
        dp[i][1] = min(dp[i-1][0], dp[i-2][0]);
    }

    cout << min(dp[n-1][0], dp[n-1][1]) << '\n';
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