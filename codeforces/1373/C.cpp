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

void demo(string str) {
    ll curr = 0, res = 0;
    for(int i = 0; i < INFINITY; i++) {
        curr = i;
        bool ok = true;

        for(int j = 0; j < str.length(); j++) {
            res++;
            if(str[i] == '+') curr++;
            else curr--;

            if(curr < 0) {
                ok = false;
                break;
            }
        }
        cout << i << ' ' << res << '\n';
        if(ok) break;
    }

    cout << res;
}

void solve() {
    string str; cin >> str;

    int ref = 0;
    ll ans = 0;
    for(int i = 0; ; i++) {
        if(str[i] == '-') {
            ref--;
            if(ref < 0 && i < str.length() - 1)  ans += i + 1, ref = 0;
            if(i == str.length() - 1) {
                if(ref < 0) ans += 2 * (i+1);
                else ans += i + 1;
                break;
            }
        }else ref++;
        if(i == str.length() - 1 && ref >= 0) {
            ans += i + 1;
            break;
        }
    }
    if(ans == 0) ans++;
    cout << ans << '\n';
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // string str; cin >> str;
    // demo(str);
    int t; cin >> t;
    while(t--){
        solve();
    }
    // solve();

}