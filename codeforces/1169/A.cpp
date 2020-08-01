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
    int n, a, x, b, y;
    cin >> n >> a >> x >> b >> y;

    vi f, s;

    for(int i = a; i != x; i != n ? i++ : i = 1) {
        f.pb(i);
    }

    f.pb(x);

    for(int i = b; i != y; i != 1 ? i-- : i = n) {
        s.pb(i);
    }

    s.pb(y);

    for(int i = 0; i < min(f.size(), s.size()); i++) {
        if(f[i] == s[i]) {
            cout << "YES";
            return;
        }
    }

    cout << "NO";
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