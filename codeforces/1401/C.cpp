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
    int n; cin >> n;

    ll arr[n], brr[n];

    ll mn = INT_MAX;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        brr[i] = arr[i];

        mn = min(mn, arr[i]);
    }

    sort(brr, brr + n);

    vll ref;

    for(int i = 0; i < n; i++) {
        if(arr[i] != brr[i]) {
            ref.pb(arr[i]);
        }
    }

    if(ref.empty()) {
        cout << "YES\n";
    }else {

        for(int i = 0; i < ref.size(); i++) {
            if(ref[i] % mn != 0) {
                cout << "NO\n";
                return;
            }
        }
        
        cout << "YES\n";

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
    cin >> t;
    while(t--) {
      solve();
    }
}