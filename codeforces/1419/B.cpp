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
#define vi vector<int>
#define vll vector<ll>
#define pb push_back


// D R U L
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

const ll mx = 1e18 + 1;
const int INF = mod;

ll power(int x, unsigned int y){
    ll res = 1;
    while(y > 0){
        if(y & 1) res = res * x;
        y >>= 1;
        x *= x;
    }
    return res;
}

vector<ll> needed;

void calc() {

    ll start = 4;

    needed.pb(1);
    needed.pb(6);

    int i = 0;

    while(start <= mx) {
        i++;

        ll temp = start;

        ll res = 0;
        ll p = 1;
        for(ll x = temp; x > 0; x /= 2) {
            res += (p*p * x);
            p *= 2;
        }

        needed.pb(res);

        start *= 2;

        if(i == 30) break;
    }
}

// Check for number of Cases!!
void solve() {
    ll x; cin >> x;

    ll ans = 0;

    ll i = 0;

    while(x > 0) {
        if(x >= needed[i]) {
            x -= needed[i];
            i++;
            ans++;
        }else {
            break;
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
    
    calc();

    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }
}