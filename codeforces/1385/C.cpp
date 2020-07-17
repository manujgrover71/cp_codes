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

void solve() {
    int n; cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int maxArrLeft[n] = {0}, maxArrRight[n] = {0};

    maxArrLeft[0] = arr[0];

    for(int i = 1; i < n; i++) {
        maxArrLeft[i] = max(arr[i], maxArrLeft[i-1]);
    }

    maxArrRight[n-1] = arr[n-1];

    for(int i = n-2; i >= 0; i--) {
        maxArrRight[i] = max(arr[i], maxArrRight[i+1]);
    }

    for(int i = n-2; i > 0; i--) {
        if(arr[i] < maxArrRight[i] && arr[i] < arr[i-1]) {
            cout << i << '\n';
            return;
        }
    }

    cout << 0 << '\n';
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