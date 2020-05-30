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
    int n; cin >> n;
    int arr[2*n];
    n = 2*n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n);

    ll ans = 1e11;
    for(int i = 0; i < n; i++){
        int ref = arr[i];
        if(i < n/2){
            ans = min(ans, (ll) abs(arr[n/2] - ref)); 
        }else if(i == n/2){
            ans = min(ans, (ll)abs(arr[i] - arr[n/2-1]));
        }else{
            ans = min(ans, (ll)abs(arr[i] - arr[n/2-1]));
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