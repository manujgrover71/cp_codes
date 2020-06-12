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
    int n, m;
    cin >> n >> m;
    int ref_size = n + m - 1;
    int ref[ref_size][2];

    memset(ref, 0, sizeof(ref));

    int sum = n + m - 2;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int a; cin >> a;
            int index = min(i + j, sum - i - j);

            if((ref_size & 1) && (index == (ref_size/2))) continue;

            // cout << index << '\n';
            if(a == 1){
                ref[index][1]++;
            }else ref[index][0]++;
        }
    }
    ll ans = 0;
    for(int i = 0; i < ref_size; i++){
        ans += min((ll)ref[i][0], (ll)ref[i][1]);
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