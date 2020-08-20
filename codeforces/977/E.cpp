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

ll power(int x, unsigned int y){
    ll res = 1;
    while(y > 0){
        if(y & 1) res = res * x;
        y >>= 1;
        x *= x;
    }
    return res;
}

const int mx = 2 * (int)1e5 + 1;

vll adj[mx];
vector<bool> vis(mx, false);

bool findEdges(int x) {

    queue<int> q;
    q.push(x);

    bool check = true;

    while(!q.empty()) {

        int front = q.front();
        q.pop();
        if(vis[front]) continue;
        
        vis[front] = true;

        if(adj[front].size() != 2) check = false;

        for(auto child : adj[front]) {
            if(!vis[child]) {
                q.push(child);
            }
        }

    }

    return check;

}

// Check for number of Cases!!
void solve() {
    
    int n, m;
    cin >> n >> m;

    while(m--) {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    ll ans = 0;

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            if(findEdges(i))
                ans++;
        }
    }

    cout << ans;

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