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
    ll arr[4];
    for(int i = 0; i < 4; i++) cin >> arr[i];

    sort(arr, arr + 4);

    if(arr[0] == arr[2]) {
        cout << arr[0]/2 << ' ' << arr[1] / 2 << ' ' << arr[2] / 2 << '\n';
    }else {
        ll x = (arr[1] - arr[0] + arr[2]) / 2;
        ll y = arr[2] - x;
        ll z = arr[0] - y;

        cout << x << ' ' << y << ' ' << z << '\n';
    }

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }
}