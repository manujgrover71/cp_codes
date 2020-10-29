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

bool checkValid(ll a, ll b, ll c) {
    if(a + b <= c || a + c <= b || b + c <= a)
        return false;

    return true;
}

// Check for number of Cases!!
void solve() {
    
    ll x, y;
    cin >> x >> y;

    ll a = y, b = y, c = y;

    ll ans = 0;

    ll turn = -1;

    while(a != x || b != x || c != x) {

        ll left = -1;
        ll right = x;

        turn++;
        turn %= 3;

        ll second, third;

        if(turn == 0) left = a, second = b, third = c;
        else if(turn == 1) left = b, second = a, third = c;
        else left = c, second = a, third = b;

        if(left == right) continue;

        while(left <= right) {
            ll mid = left + (right - left) / 2;

            if(checkValid(mid, second, third)) {
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }

        if(turn == 0) a = left - 1;
        else if(turn == 1) b = left - 1;
        else c = left - 1;

        // turn++;
        ans++;

        debug(a, b, c);
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