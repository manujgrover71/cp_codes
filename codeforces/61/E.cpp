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

ll n;
vll arr;
vector<vll> tree;
void build_tree(ll si, ll ss, ll se) {
    if(ss == se) {
        tree[si].pb(arr[ss]);
        return;
    }
    
    ll mid = (ss + se) / 2;
    build_tree(2*si, ss, mid);
    build_tree(2*si + 1, mid + 1, se);
    
    int a = tree[2*si].size();
    int b = tree[2*si + 1].size();
    
    int i = 0, j = 0;
    
    while(i < a && j < b) {
        if(tree[2*si][i] < tree[2*si + 1][j]) {
            tree[si].pb(tree[2*si][i++]);
        }else {
            tree[si].pb(tree[2*si + 1][j++]);
        }
    }
    
    while(i < a) {
        tree[si].pb(tree[2*si][i++]);
    }
    
    while(j < b) {
        tree[si].pb(tree[2*si + 1][j++]);
    }
}

ll greater_query(ll si, ll ss, ll se, ll qs, ll qe, ll val) {
    
    if(ss > qe || se < qs) return 0;
    
    if(ss >= qs && se <= qe) {
        ll ans = upper_bound(all(tree[si]), val) - tree[si].begin();
        return tree[si].size() - ans;
    }
    
    ll mid = (ss + se) / 2;
    return greater_query(2*si, ss, mid, qs, qe, val) + greater_query(2*si + 1, mid + 1, se, qs, qe, val);
}

ll lower_query(ll si, ll ss, ll se, ll qs, ll qe, ll val) {
    if(ss > qe || se < qs) return 0;
    
    if(ss >= qs && se <= qe) {
        ll ans = lower_bound(all(tree[si]), val) - tree[si].begin();
        return ans;
    }
    
    ll mid = (ss + se) / 2;
    return lower_query(2*si, ss, mid, qs, qe, val) + lower_query(2*si + 1, mid + 1, se, qs, qe, val);
}

// Check for number of Cases!!
void solve() {
    cin >> n;
    
    arr = vll(n + 1);
    tree = vector<vll> (4 * n);
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    build_tree(1, 1, n);
    
    ll ans = 0;
    
    for(int i = 2; i < n; i++) {
        // cout << greater_query(1, 1, n, 1, i-1, arr[i]) << ' ' << lower_query(1, 1, n, i+1, n, arr[i]) << '\n';
        ans += greater_query(1, 1, n, 1, i-1, arr[i]) * lower_query(1, 1, n, i+1, n, arr[i]);
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