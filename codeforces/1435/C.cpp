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
    vll arr(6);
    cin >> arr;

    ll n; cin >> n;

    vll brr(n);

    vector<pair<ll, ll>> ref;

    for(int i = 0; i < n; i++) {
        cin >> brr[i];
        for(int j = 0; j < 6; j++) {
            ref.pb({brr[i] - arr[j], i});
        }
    }

    sort(all(ref));

    map<ll, ll> mp;

    ll ans = LLONG_MAX;
    int j = 0;
    for(int i = 0; i < 6*n; i++) {
        
        mp[ref[i].second]++;

        while(mp.size() > n) {
            mp[ref[j].second]--;
            if(mp[ref[i].second] == 0) {
                mp.erase(ref[i].second);
            }
            j++;
        }

        while(mp.size() == n) {
            ans = min(ans, ref[i].first - ref[j].first);
            mp[ref[j].second]--;
            if(mp[ref[j].second] == 0) {
                mp.erase(ref[j].second);
            }
            j++;
        }
    }

    cout << ans;
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