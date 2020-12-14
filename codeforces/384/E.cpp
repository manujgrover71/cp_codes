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

const int mx = 2e5 + 5;
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

class BIT {

    vll bit;
    ll N;

    public:

    void update(ll x, ll val) {
        ll ind = x;
        while(ind <= N) {
            bit[ind] += val;
            ind += ((ind) & (-ind));
        }
    }

    BIT(ll n) {
        N = mx;
        bit = vll(N, 0);
    }

    ll getSum(ll x) {

        if(x < 0) return 0;

        ll ind = x;
        ll sum = 0;

        while(ind > 0) {
            sum += bit[ind];
            ind -= ((ind) & (-ind));
        }

        return sum;
    }

    ll getValue(ll x) {
        return getSum(x) - getSum(x-1);
    }

    void changeElem(ll x, ll val) {
        update(x+1, val-getValue(x));
    }

};

vll adj[mx];
vll in, out;
ll timer = 0;
vll depth;

void dfs(ll curr, ll par, ll d) {
    in[curr] = ++timer;
    depth[curr] = d;
    
    for(auto child : adj[curr]) {
        if(child != par) {
            dfs(child, curr, d + 1);
        }
    }
    
    out[curr] = timer;
}

// Check for number of Cases!!
void solve() {
    ll n, m;
    cin >> n >> m;
    
    in = vll (n + 10);
    out = vll (n + 10);
    depth = vll (n + 10);
    vll arr(n + 1);
    
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    for(int i = 1; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    dfs(1, 0, 0);
    
    BIT bit(n);
    
    while(m--) {
        ll op, x;
        cin >> op >> x;
        
        if(op == 1) {
            ll val; cin >> val;
            
            if(depth[x] & 1) val = -val;
            bit.update(in[x], val);
            bit.update(out[x] + 1, -val);
        }else {
            ll extra = bit.getSum(in[x]);
            if(depth[x] & 1) extra = -extra;
            cout << extra + arr[x] << '\n';
        }
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