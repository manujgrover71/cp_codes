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

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vi left(n, 1), right(n, 1);

    int ans = 1;

    for(int i = 1; i < n; i++) {
        if(arr[i] > arr[i-1]) left[i] = left[i-1] + 1;
        ans = max(ans, left[i]);
    }

    for(int i = n-2; i >= 0; i--) {
        if(arr[i+1] > arr[i]) right[i] = right[i+1] + 1;
        ans = max(ans, right[i]);
    }

    for(int i = 0; i < n-2; i++) {
        if(arr[i] < arr[i+2])
            ans = max(ans, left[i] + right[i+2]);
    }

    cout << ans;
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