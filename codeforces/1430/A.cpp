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

// Check for number of Cases!!
void solve() {
    ll n; cin >> n;

    // a = ((n - (5*b + 7*c)) / 3

    ll upper_limit_b = n / 5 + 1;
    ll upper_limit_c = n / 7 + 1;

    for(int i = 0; i < upper_limit_b; i++) {
        for(int j = 0; j < upper_limit_c; j++) {
            if((n - (5*i + 7*j)) % 3 == 0) {
                cout << ((n - (5*i + 7*j)) / 3) << ' ' << i << ' ' << j << '\n';
                return;
            }
        }
    }
    
    cout << "-1\n";

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }
}