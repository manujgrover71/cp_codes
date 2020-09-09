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

pair<ll, ll> ask(ll x, ll y) {
    cout << "? " << x << ' ' << y << endl;
    ll res; cin >> res;
    cout << "? " << y << ' ' << x << endl;
    ll res2; cin >> res2;
    return {res, res2};
}

// Check for number of Cases!!
void solve() {
    ll n; cin >> n;

    vector<ll> ans(n+1, -1);

    int l = 1, r = n;

    ll sum = 0;

    while(l < r) {

        pair<ll, ll> res = ask(l, r);

        if(res.first > res.second) {
            ans[l] = res.first;
            l++;
        }else {
            ans[r] = res.second;
            r--;
        }

        sum += max(res.first, res.second);
    }

    ans[l] = (n * (n+1))/2  - sum;

    cout << "! ";

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }

    cout << endl;
}

int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("/ATOMCODES/input.txt", "r", stdin);
    // freopen("/ATOMCODES/output.txt", "w", stdout);
    // #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }
}