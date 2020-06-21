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
    int arr[2*n];
    vi odd, even;
    for(int i = 0; i < 2*n; i++) {
        cin >> arr[i];
        if(arr[i] % 2 == 0) even.pb(i+1);
        else odd.pb(i+1);
    }
    int count = 0;
    for(int i = 0; i < even.size(); i+=2) {
        if(i+1 < even.size()) {
            cout << even[i] << ' ' << even[i+1] << '\n';
            count++;
        }
        if(count == n-1) return;
    }

    for(int i = 0; i < odd.size(); i+=2) {
        if(i+1 < odd.size()) {
            cout << odd[i] << ' ' << odd[i+1] << '\n';
            count++;
        }
        if(count == n-1) return;
    }

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