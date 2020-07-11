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
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;


    // 1-> a , d;
    // 2-> b,c,d;

    int type1 = min(a, d);
    int type2 = min({b, c, d});


    ll ans = 0;

    ll t1 = type1;
    ll t2 = d - t1;

    if(t2 >= type2) {
        cout << t1 * e + type2 * f;
        return;
    }

    while(t1 >= 0 || t2 <= type2) {
        if(t1 >= 0 && t2 <= type2) {
            ans = max(ans, t1 * e + t2 * f);
        } else {
            if(t1 >= 0) {
                ans = max(ans, t1 * e);
            }

            if(t2 <= type2) {
                ans = max(ans, t2 * f);
            }
        }
        t1--;
        t2++;
    }

    cout << ans << '\n';
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