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

vll parent;

ll find_parent(ll x) {
    if(parent[x] == x) return x;
    return parent[x] = find_parent(parent[x]);
}

// Check for number of Cases!!
void solve() {
    ll n, m;
    cin >> n >> m;
    
    parent = vll (n+10);
    
    for(int i = 1; i <= n + 9; i++) parent[i] = i;
    
    vll ans(n+1, 0);
    
    while(m--) {
        ll l, r, x;
        cin >> l >> r >> x;
        
        ll find = find_parent(l);
        
        while(find <= r) {
            if(find == x) find++;
            else {
                parent[find] = find + 1;
                ans[find] = x;
            }
            
            find = find_parent(find);
        }
    }
    
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
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