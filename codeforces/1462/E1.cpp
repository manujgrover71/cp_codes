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

ll nc2(ll x) {
    return (x * (x-1)) / 2;
}

// Check for number of Cases!!
void solve() {
    ll n; cin >> n;
    vll arr(n);
    cin >> arr;
    
    sort(all(arr));
    
    ll l = 0;
    
    ll ans = 0;
    
    for(int i = 2; i < n; i++) {
        if(abs(arr[i] - arr[l]) <= 2) {
            if((i - l + 1) >= 3) {
                ans += nc2(i - l);
            }
        }else {
            while(l <= i && abs(arr[i] - arr[l]) > 2) l++;
            if((i - l + 1) >= 3) ans += nc2(i - l);
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