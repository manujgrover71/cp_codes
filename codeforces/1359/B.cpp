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
#define pb(x) push_back(x)

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
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    if(2*x < y) y = 2*x;

    char arr[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    ll ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(arr[i][j] == '.'){
                if(j+1 < m && arr[i][j+1] == '.') {
                    ans += y;
                    j++;
                }
                else ans += x;
            }
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