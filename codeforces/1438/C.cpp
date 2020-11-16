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

vector<vector<ll>> vis(100, vector<ll> (100, 0));
vector<vector<ll>> col(100, vector<ll> (100, 0));

ll n, m;

bool isValid(ll x, ll y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(vector<vector<ll>> arr, ll x, ll y, ll c) {
    vis[x][y] = true;
    col[x][y] = c;
    
    for(int i = 0; i < 4; i++) {
        ll newX = x + dx[i];
        ll newY = y + dy[i];
        
        if(isValid(newX, newY) && !vis[newX][newY]) {
            vis[newX][newY] = true;
            dfs(arr, newX, newY, c^1);
        }
    }
    
}

// Check for number of Cases!!
void solve() {
    cin >> n >> m;
    
    vector<vector<ll>> arr(n, vll(m));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            // vis[i][j] = false;
            // col[i][j] = 0;
        }
    }
    
    // dfs(arr, 0, 0, 0);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << arr[i][j] + (i+j+arr[i][j])%2 << ' ';
        }cout << '\n';
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
    cin >> t;
    while(t--) {
      solve();
    }
}