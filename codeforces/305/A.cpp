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
    bool zero = false, hundred = false;
    int extra = -1, one_ten = -1, tens = -1;

    for(int i = 0; i < n; i++) {
        int temp; cin >> temp;
        if(temp == 0) {
            zero = true;
        }else if(temp == 100) {
            hundred = true;
        }else if(temp < 10) {
            one_ten = temp;
        }else if(temp % 10 == 0) {
            tens = temp;
        }else {
            extra = temp;
        }
    }

    vi ans;

    if(zero) ans.pb(0);
    if(hundred) ans.pb(100);
    if(one_ten != -1) ans.pb(one_ten);
    if(tens != -1) ans.pb(tens);
    if(one_ten == -1 && tens == -1 && extra != -1) ans.pb(extra);

    cout << ans.size() << '\n';
    for(auto i : ans) {
        cout << i << ' ';
    }
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