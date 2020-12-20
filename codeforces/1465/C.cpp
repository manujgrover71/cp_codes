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

template <typename T> istream &operator>>
(istream &is, vector<T> &vec) 
{   for (auto &v : vec) is >> v; return is; }

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
    ll n,m;
    cin>>n>>m;
    
    vector<pair<int, int>> ref(n + 1, {-1, -1});
    
    for(int i = 0; i < m; i++){
        ll a, b;
        cin >> a >> b;
        if(a != b) {
            ref[a] = {a, b};
        }
    }
    
    ll ans = 0;
    
    for(int i = 1; i <= n; i++) {
        if(ref[i].first != -1) {
            int f = ref[i].first;
            ll sz = 1;
            ll temp = ref[i].second;
            ref[i].first = -1;
            while(temp != f) {
                if(ref[temp].first == -1) break;
                sz++;
                ref[temp].first = -1;
                temp = ref[temp].second;
            }
            if(temp == f) ans += sz + 1;
            else ans += sz;
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
    cin >> t;
    while(t--) {
      solve();
    }
}