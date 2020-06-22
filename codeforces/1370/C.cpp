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

bool isPrime(ll n) {
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) return false;
    }

    return true;
}

void solve() {
    ll n; cin >> n;
    
    if(n & 1 && n != 1 || n == 2) {
        cout << "Ashishgup\n";
        return;
    }else if(n == 1) {
        cout << "FastestFinger\n";
        return;
    }

    if(!(n&(n-1))) {
        cout << "FastestFinger\n";
        return;
    }

    if(n % 2 == 0 && (n/2) & 1 && isPrime(n/2)) {
        cout << "FastestFinger\n";
        return;
    }

    cout << "Ashishgup\n";

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
        // cout << t << '\n';
        solve();
    }

}