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

// ------------------------------------------------

template <typename T> istream &operator>>
(istream &is, vector<T> &vec) 
{   for (auto &v : vec) is >> v; return is; }

template<typename T> 
void dout(string name, T arg) {
    cerr << arg << endl;
}

template<typename T1, typename... T2> 
void dout(string names, T1 arg, T2... args) {
    cerr << arg << " | ";
    dout(names.substr(names.find(',') + 2), args...);
}

#ifndef ONLINE_JUDGE
    #define debug(...) dout(#__VA_ARGS__, __VA_ARGS__)
#else
    #define debug(...) 
#endif

// --------------------------------------------------

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define ll long long
#define mod 998244353
#define nod 998244353
#define vi vector<int>
#define vll vector<ll>
#define pb push_back


// D R U L
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

const int mx = 3e5 + 5;
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

ll ncr(ll r, ll n) {
    return (((fac[n] * invfac[r]) % mod) * invfac[n - r]) % mod;
}


// Check for number of Cases!!
void solve() {
    ll n; cin >> n;
    vll arr(2*n);
    cin >> arr;

    sort(all(arr));

    ll ans = 0;

    for(int i = 0, j = 2*n-1; i < n; i++, j--) {
        ans = (ans + arr[j] - arr[i]) % mod;
    }
    
    ans = (ans + mod) % mod;

    cout << (ans * ncr(n, 2*n) % mod);
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
    // cin >> t;
    init();
    while(t--) {
      solve();
    }
}