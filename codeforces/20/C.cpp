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

const ll INF = 1e17;

// Check for number of Cases!!
void solve() {
    int nodes, edges;
    cin >> nodes >> edges;

    vector<pair<ll, ll> > adj[nodes+1];

    vector<ll> dis(nodes+1, INF), par(nodes+1, -1);
    vector<bool> vis(nodes+1, false);

    while(edges--) {
        ll a, b, w;
        cin >> a >> b >> w;

        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>> ,  greater<pair<ll, ll>> > pq;
    pq.push({0, 1});

    dis[1] = 0;

    while(!pq.empty()) {

        ll curr = pq.top().second;
        ll cost = pq.top().first;

        pq.pop();
        if(vis[curr]) continue;

        vis[curr] = true;

        for(auto child : adj[curr]) {

            ll to = child.first;
            ll childCost = child.second;

            if(dis[curr] + childCost < dis[to]) {
                dis[to] = dis[curr] + childCost;
                par[to] = curr;
                pq.push({dis[to], to});
            }
        }
    }

    if(dis[nodes] == INF) {
        cout << "-1";
    }else {

        vector<ll> ans;

        while(nodes != -1) {
            ans.pb(nodes);
            nodes = par[nodes];
        }

        for(int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i] << ' ';
        }

    }
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