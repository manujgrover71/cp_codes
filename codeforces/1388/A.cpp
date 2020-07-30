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

    int sum = 6 + 10 + 14;


    if(n > sum) {

        if(n != 36 && n != 40 && n != 44) {
            cout << "YES\n";
            cout << "6 10 14 " << n - sum << '\n';
        }else if(n > 10+6+15) {
            cout << "YES\n";
            cout << "10 6 15 " << n - (10 + 6 + 15) << '\n';
        }else {
            cout << "NO\n";    
        }

    }else {
        cout << "NO\n";
    }

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // seive();
    int t; cin >> t;
    while(t--){
        solve();
    }

}