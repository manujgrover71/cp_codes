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

class DSU {

    private:
        vector<ll> parent;
        vector<ll> sz;

    public:

        DSU(ll size) {
            parent.resize(size+1);
            sz.resize(size+1);

            for(int i = 1; i <= size; i++) {
                make_set(i);
            }
        }

        void make_set(ll curr) {
            parent[curr] = curr;
            sz[curr] = 1;
        }

        ll find_parent(ll curr) {
            return (parent[curr] == curr) ? curr : find_parent(parent[curr]);
        }

        bool union_set(ll x, ll y) {
            x = find_parent(x);
            y = find_parent(y);

            if(x != y) {
                if(sz[x] < sz[y])
                    swap(x, y);

                parent[y] = x;
                sz[x] += sz[y];
                return true;
            }
            
            return false;
        }
};

// Check for number of Cases!!
void solve() {
    ll n, x;
    cin >> n >> x;
    
    DSU dsu(n+1);
    
    ll ans = 0;
    
    for(int i = 0; i < x; i++) {
       ll a, b;
       cin >> a >> b;
       
       if(a == b) continue;
       
       ans++;
       if(!dsu.union_set(a, b)) ans++;
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