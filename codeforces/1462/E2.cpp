#include <algorithm>
#include <iostream>
#include <climits>
#include <iomanip>
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
{   for (auto &v : vec) is >> v; return is; }

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

const int mx = 2e5 + 5;
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

ll nc2(ll x) {
    return (x * (x-1)) / 2;
}

vll fac(mx, 0), invfac(mx, 0);

void init() {
    fac[0] = 1;
    for(int i = 1; i <= mx; i++) {
        fac[i] = (i * fac[i-1]) % mod;
    }
    invfac[mx] = power(fac[mx], mod - 2);
    for(int i = mx - 1; i >= 0; i--) {
        invfac[i] = ((i+1) * invfac[i+1]) % mod;
    }
}

ll ncr(ll n, ll r) {
    return (((fac[n] * invfac[r]) % mod) * invfac[n - r]) % mod;
}

// Check for number of Cases!!
void solve() {
    ll n; cin >> n;
    ll m, k;
    cin >> m >> k;
    vll arr(n);
    cin >> arr;
    
    sort(all(arr));
    
    ll l = 0;
    
    ll ans = 0;
    
    for(int i = m-1; i < n; i++) {
        if(abs(arr[i] - arr[l]) <= k) {
            if((i - l + 1) >= m) {
                ans = (ans + ncr(i - l, m-1)) % mod;
            }
        }else {
            while(l <= i && abs(arr[i] - arr[l]) > k) l++;
            if((i - l + 1) >= m) {
                ans = (ans + ncr(i - l, m - 1)) % mod;
            }
        }
    }
    
    if(ans < 0) ans += mod;
    
    cout << ans << '\n';
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    freopen("/ATOMCODES/err_output.txt", "w", stderr);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    init();
    cin >> t;
    while(t--) {
      solve();
    }
}