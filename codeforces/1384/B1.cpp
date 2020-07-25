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
    int n, k, l;
    cin >> n >> k >> l;

    int maxi = k, mini = -k;
    bool check = true;

    for(int i = 0; i < n; i++) {
        int temp; cin >> temp;

        if(temp > l) {
            check = 0;
        }

        maxi = min(l - temp, k);

        if(maxi == k) {
            mini = -k;
        }else {
            mini = max(mini + 1, -maxi);
        }

        if(mini > maxi) {
            check = 0;
        }
    }

    if(!check) {
        cout << "No\n";
    }else {
        cout << "Yes\n";
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