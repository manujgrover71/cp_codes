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
    int n; cin >> n;
    int arr[n], count = 0, even = 0, odd = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] % 2 != i % 2) {
            if(arr[i] % 2 == 0) even++;
            else odd++;
            count++;
        }
    }

    // cout << count << '\n';

    if(count % 2 == 0 && even == odd) {
        cout << count/2 << '\n';
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