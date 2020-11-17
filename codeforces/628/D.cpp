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

ll d, k, sz;
vll arr;

ll dp[2005][2005][2];

void clear() {
    for(int i = 0; i < 2005; i++) {
        for(int j = 0; j < 2005; j++) {
            for(int l = 0; l < 2; l++) {
                dp[i][j][l] = -1;
            }
        }
    }
}

ll recur(ll pos, ll num, bool flag) {
    if(pos == arr.size()) {
        if(num % k == 0) {
            return 1;
        }
        return 0;
    }

    if(dp[pos][num][flag] != -1) return dp[pos][num][flag];

    ll limit = 1;
    
    if(!flag) limit = arr[pos];
    else limit = 9;
    
    ll result = 0;
    for(int i = 0; i <= limit; i++) {

        if(pos % 2 == 0 && i == d) continue;
        if(pos & 1 && i != d) continue;
        
        if(flag || i < limit)
            result = (result + recur(pos + 1, (num * 10 + i) % k, true)) % mod;
        else result = (result + recur(pos + 1, (num * 10 + i) % k, false)) % mod;
    }
    
    return dp[pos][num][flag] = result;
}

ll f(string x) {
    clear();
    string num = x;
    sz = num.size();
    
    arr = vll(sz);
    for(int i = 0; i < sz; i++) {
        arr[i] = num[i] - '0';
    }
    
    return recur(0, 0, false);
}

ll checkForL(string l) {
    clear();
    string L = l;
    ll ref = 0;
    for(int i = 0; i < L.size(); i++) {
        if((i & 1 && L[i] - '0' != d) || (i % 2 == 0 && L[i] - '0' == d)) return 0;
        ref = (ref * 10 + (L[i] - '0')) % k;
    }
    if(ref % k == 0)
        return 1;
    return 0;
}

// Check for number of Cases!!
void solve() {
    string l, r;
    cin >> k >> d;
    cin >> l >> r;
    ll ans = (f(r) - f(l) + mod) % mod;
    ans += checkForL(l);
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
    // cin >> t;
    while(t--) {
      solve();
    }
}