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
{ for (auto &v : vec) is >> v; return is; }

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
    ll n; cin >> n;

    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    vector<pair<ll, ll>> arr;

    for(int i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;

        ll ifr1 = (abs(x - x1) * abs(x - x1)) + (abs(y - y1) * abs(y - y1));
        ll ifr2 = (abs(x - x2) * abs(x - x2)) + (abs(y - y2) * abs(y - y2));
        
        arr.pb({ifr1, ifr2});
    }

    sort(all(arr));

    ll ans = 1e18;

    if(arr.size() == 1) {
        cout << min(arr[0].first, arr[0].second);
        return;
    }

    for(int i = 0; i < n; i++) {
        ll first = arr[i].first;
        ll second = 0;
        for(int j = 0; j < n; j++) {
            if(arr[j].first <= first) continue;
            second = max(second, arr[j].second);
        }
        ans = min(ans, first + second);
    }

    for(int i = 0; i < n; i++) {
        ll first = arr[i].second;
        ll second = 0;
        for(int j = 0; j < n; j++) {
            if(arr[j].second <= first) continue;
            second = max(second, arr[j].first);
        }
        ans = min(ans, first + second);
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