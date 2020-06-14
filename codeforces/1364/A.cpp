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

void solve() {
    int n, x;
    cin >> n >> x;
    int arr[n];
    
    ll sum = 0;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }   
    ll i = 0, sumRef = sum;
    while(sum % x == 0){
        if(n == i) break;
        sum -= arr[i];
        i++;
    }

    
    ll ans = 0;
    if(sum % x){
        ans = n - i;
    }

    i = n-1;

    while(sumRef % x == 0){
        if(i == -1) break;
        sumRef -= arr[i];
        i--;
    }

    if(sumRef % x) {
        ans = max(ans, i + 1);
    }

    if(ans){
        cout << ans << '\n';
    }else cout << "-1\n";
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