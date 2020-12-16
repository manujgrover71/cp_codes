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
    ll n, m;
    cin >> n >> m;
    
    string str[n];
    for(int i = 0; i < n; i++) cin >> str[i];
    
    ll ans = 0;
    
    vector<vll> ref(n, vll(m, 0));
    
    for(int i = 0; i < n; i++) {
        ll cnt = 0;
        for(int j = 0; j < m; j++) {
            if(str[i][j] == '*') cnt++;
            else cnt = 0;
            ref[i][j] = cnt;
        }
        
        cnt = 0;
        for(int j = m - 1; j >= 0; j--) {
            if(str[i][j] == '*') cnt++;
            else cnt = 0;
            ref[i][j] = min(ref[i][j], cnt);
        }
    }
     
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(str[i][j] == '*') {
                ans++;
                ll side = 1;
                for(int k = i + 1; k < n; k++) {
                    if(ref[k][j] >= side + 1) ans++;
                    else break;
                    side++;
                }
            }
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