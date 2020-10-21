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

// ------------------------------------------------

template <typename T> istream &operator>>
(istream &is, vector<T> &vec) 
{   for (auto &v : vec) is >> v; return is; }

template<typename T> 
void dout(string name, T arg) {
    cerr << arg << endl;
}

template<typename T1, typename... T2> 
void dout(string names, T1 arg, T2... args) {
    cerr << arg << " | ";
    dout(names.substr(names.find(',') + 2), args...);
}

#ifndef ONLINE_JUDGE
    #define debug(...) dout(#__VA_ARGS__, __VA_ARGS__)
#else
    #define debug(...) 
#endif

// --------------------------------------------------

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

const int mx = 71;
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

ll n, m, k;
ll dp[mx][mx][mx][mx];
ll arr[mx][mx];

ll recur(ll row, ll col, ll cnt, ll sum) {

    if(row == n) {
        if(sum % k != 0) return -INF;
        return 0;
    }

    if(col == m) {
        if(cnt > m/2) return -INF;
        return recur(row + 1, 0, 0, sum);
    }

    if(dp[row][col][cnt][sum] != -INF)
        return dp[row][col][cnt][sum];

    // if this element is not taken
    ll option1 = recur(row, col + 1, cnt, sum);

    // if this element is taken
    ll option2 = recur(row, col + 1, cnt + 1, (sum + arr[row][col]) % k) + arr[row][col];

    return dp[row][col][cnt][sum] = max(option1, option2);
}


// Check for number of Cases!!
void solve() {
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int cnt = 0; cnt < m; cnt++) {
                for(int rem = 0; rem < k; rem++) {
                    dp[i][j][cnt][rem] = -INF;
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    cout << recur(0, 0, 0, 0) << '\n';
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