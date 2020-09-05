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

// D R U L
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

const int mx = 1e6 + 5;
const int INF = mod;

ll power(int x, unsigned int y){
    ll res = 1;
    while(y > 0){
        if(y & 1) res = res * x;
        y >>= 1;
        x *= x;
    }
    return res;
}

ll sum(ll n) {

    ll res = 0;

    while(n > 0) {
        res += (n % 10);
        n /= 10;
    }

    return res;
}

// Check for number of Cases!!
void solve() {
    ll n, k;
    cin >> n >> k;

    if(sum(n) <= k) {
        cout << "0\n";
        return;
    }

    ll p = 1;

    ll ans = 0;

    for(int i = 0; i < 18; i++) {

        ll num = (n / p) % 10;

        ll toAdd = p * ((10 - num) % 10);

        n += toAdd;

        ans += toAdd;

        if(sum(n) <= k)
            break;

        p *= 10;

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
    
    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }
}