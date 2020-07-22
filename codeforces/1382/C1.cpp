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

string r(string str, int last) {
    for(int i = 0; i < last; i++) {
        if(str[i] == '1') 
            str[i] = '0';
        else str[i] = '1';
    }
    return str;
}

void solve() {
    int n; cin >> n;
    string a, b;
    cin >> a >> b;

    a += '0';
    b += '0';
    vi ans;

    for(int i = 0; i < n; i++) {
        if(a[i] != a[i+1]) {
            ans.pb(i+1);
        }
    }

    for(int i = n-1; i >= 0; i--) {
        if(b[i] != b[i+1]) {
            ans.pb(i+1);
        }
    }

    cout << ans.size() << ' ';

    for(auto i : ans) {
        cout << i << ' ';
    }

    cout << '\n';
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