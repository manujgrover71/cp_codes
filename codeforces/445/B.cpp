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

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define ll long long
#define mod 1000000007
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
        if(y & 1) res = res * x;
        y >>= 1;
        x *= x;
    }
    return res;
}



int nodes;
vector<int> adj[51];
vector<bool> vis(51, false);

void dfs(int curr) {
    vis[curr] = true;

    for(auto child : adj[curr]) {
        if(!vis[child]) {
            dfs(child);
        }
    }
}

// Check for number of Cases!!
void solve() {
    ll edges;
    cin >> nodes >> edges;

    while(edges--) {
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    ll c = 0;

    for(int i = 1; i <= nodes; i++) {
        if(!vis[i]) {
            c++;
            dfs(i);
        }
    }

    cout << power(2, nodes - c) << '\n';

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }
}