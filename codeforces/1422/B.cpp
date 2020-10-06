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

template <typename T> istream &operator>>
(istream &is, vector<T> &vec) 
{ for (auto &v : vec) is >> v; return is; }

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define ll long long
#define mod 1000000007
#define nod 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pb push_back


// D R U L
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

const int mx = 1e6 + 5;
const int INF = mod;

ll power(ll x, ll y){
    ll res = 1;
    while(y > 0){
        if(y & 1) res = (res * x) % nod;
        y >>= 1;
        x = (x * x) % nod;
    }
    return (res % nod);
}



// Check for number of Cases!!
void solve() {
    ll n, m;
    cin >> n >> m;

    ll arr[n][m];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    ll ans = 0;

    for(int i = 0; i < n/2; i++) {
        for(int j = 0; j < m/2; j++) {
            ll a = arr[i][j];
            ll b = arr[n - 1 - i][j];
            ll c = arr[n - 1 - i][m - 1 -j];
            ll d = arr[i][m - 1 - j];

            vll ref{a, b, c, d};

            sort(all(ref));

            for(int k = 0; k < 4; k++) {
                if(k == 1) continue;
                ans += abs(ref[k] - ref[1]);
            }
        }
    }

    if(n & 1) {
        for(int i = 0; i < m/2; i++) {
            ll a = arr[n/2][i];
            ll b = arr[n/2][m - 1 - i];
            ll x = (a + b) / 2;
            ans += abs(x - a);
            ans += abs(x - b);
        }
    }

    if(m & 1) {
        for(int i = 0; i < n/2; i++) {
            ll a = arr[i][m/2];
            ll b = arr[n - 1 - i][m/2];
            ll x = (a + b) / 2;
            ans += abs(x - a);
            ans += abs(x - b);
        }
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