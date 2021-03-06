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
    ll arr[n];
    ll mx = -1;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }

    if(mx == 1) {
        for(int i = 0; i < n-1; i++) cout << 1 << ' ';
        cout << '2';
        return;
    }

    sort(arr, arr + n);
    cout << "1 ";
    for(int i = 0; i < n-1; i++) cout << arr[i] << ' ';
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