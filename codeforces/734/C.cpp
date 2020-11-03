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



// Check for number of Cases!!
void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    ll x, s;
    cin >> x >> s;

    vll a(m), b(m);
    cin >> a >> b;

    vector<pair<ll, ll>> ref;

    for(int i = 0; i < m; i++) {
        ref.pb({a[i], b[i]});
    }

    sort(all(ref)); // first => time, second => cost

    vll c(k), d(k);
    cin >> c >> d;

    ll ans = x * n;

    for(int i = 0; i < m; i++) {
        ll moneyLeft = s - ref[i].second;

        if(moneyLeft >= d[0]) {
            ll left = 0, right = k-1;
            while(left <= right) {
                ll mid = left + (right - left) / 2;
                if(d[mid] <= moneyLeft) {
                    left = mid + 1;
                }else {
                    right = mid - 1;
                }
            }
            left--;
            ll potionLeft = n - c[left];
            ans = min(ans, potionLeft * ref[i].first);
        }
        if(moneyLeft >= 0) {
            ans = min(ans, ref[i].first * n);
        }
        if(d[0] <= s) {

            ll left = 0, right = k-1;
            while(left <= right) {
                ll mid = left + (right - left) / 2;
                if(d[mid] <= s) {
                    left = mid + 1;
                }else {
                    right = mid - 1;
                }
            }
            left--;
            ll potionLeft = n - c[left];
            ans = min(ans, potionLeft * x);
        }
    }
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