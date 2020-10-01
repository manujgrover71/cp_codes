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

ll fact[mx], invFact[mx];


ll moduloInverse(ll n) {
    return power(n, mod-2);
}

void factorial() {
    fact[0] = 1;

    for(int i = 1; i < mx; i++) {
        fact[i] = (fact[i-1] * i) % mod;
    }

    invFact[mx-1] = moduloInverse(fact[mx-1]);

    for(int i = mx-1; i > 0; i--) {
        invFact[i-1] = (i * invFact[i]) % mod;
    }
}

ll ncr(ll n, ll r) {
    if(n < r || r < 0) return 0;

    ll res = (fact[n] * invFact[r]) % mod;
    res = (res * invFact[n-r]) % mod;

    return res;
}

// Check for number of Cases!!
void solve() {
    string str; cin >> str;

    ll y = 0, x = 0;

    for(char ch : str) {
        if(ch == ')')
            y++;
    }

    ll ans = 0;

    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(') {
            ll curr = ncr(x+y, y-1);
            ans = (ans + curr) % mod;
            x++;
        }else y--;
    }

    cout << ans;

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    factorial();
    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }
}