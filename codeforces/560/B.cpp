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


ll firsta, seconda, thirda, fourtha;
ll firstb, secondb, thirdb, fourthb;

bool check(ll x, ll y) {
    if(firsta <= x && firstb <= y) return true;
    if(firstb <= x && firsta <= y) return true;
    if(seconda <= x && secondb <= y) return true;
    if(secondb <= x && seconda <= y) return true;
    if(thirda <= x && thirdb <= y) return true;
    if(thirdb <= x && thirda <= y) return true;
    if(fourtha <= x && fourthb <= y) return true;
    if(fourthb <= x && fourtha <= y) return true;
    return false;
}

// Check for number of Cases!!
void solve() {
    ll a1, b1;
    cin >> a1 >> b1;

    ll a2, b2;
    cin >> a2 >> b2;

    ll a3, b3;
    cin >> a3 >> b3;

    ll refa1, refa2;

    firsta = a2 + a3, firstb = max(b2, b3);
    seconda = a2 + b3, secondb = max(b2, a3);
    thirda = max(a2, a3), thirdb = b2 + b3;
    fourtha = max(a2, b3), fourthb = b2 + a3;

    debug(firsta, firstb);
    debug(seconda, secondb);
    debug(thirda, thirdb);
    debug(fourtha, fourthb);

    if(check(a1, b1) || check(a2, b2)) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }
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