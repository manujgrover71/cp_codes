#include <algorithm>
#include <iostream>
#include <climits>
#include <cassert>
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
{ for (auto &v : vec) is >> v; return is; }

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

ll power(int x, unsigned int y){
    ll res = 1;
    while(y > 0){
        if(y & 1) res = res * x;
        y >>= 1;
        x *= x;
    }
    return res;
}


int nodes;
vector<int> adj[mx];
vector<int> centroids;
vector<int> subTreeSize(mx, 0);
vector<int> vis(mx, false);
int ref, ref2;
bool ok = true;

void clearAll() {
    for(int i = 0; i <= nodes; i++) {
        adj[i].clear();
        subTreeSize[i] = 0;
        vis[i] = false;
    }
    ok = true;
    centroids.clear();
}

void findCentroid(int curr, int parent) {
    subTreeSize[curr] = 1;
    bool is_centroid = true;

    for(auto child : adj[curr]) {
        if(child != parent) {
            findCentroid(child, curr);
            subTreeSize[curr] += subTreeSize[child];
            if(subTreeSize[child] > nodes / 2) is_centroid = false;
        }
    }

    if(nodes - subTreeSize[curr] > nodes / 2) is_centroid = false;
    if(is_centroid) centroids.pb(curr);
}

void dfs(int curr, int parent) {

    if(vis[curr] && !ok) return;

    vis[curr] = true;

    for(auto child : adj[curr]) {
        if(child != parent && !vis[child]) {
            if(!ok) return;
            dfs(child, curr);
        }
    }

    if(ok) {
        ref = curr;
        ref2 = parent;
        ok = false;
    }
}

// Check for number of Cases!!
void solve() {
    cin >> nodes;

    for(int i = 1; i < nodes; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    findCentroid(1, -1);

    // cout << ""

    if(centroids.size() == 1) {
        int centroid = centroids[0];
        int other_node = adj[centroid][0];
        cout << centroid << ' ' << other_node << '\n';
        cout << centroid << ' ' << other_node << '\n';
    }else if(centroids.size() ==  2) {

        // cout << centroids[0] << ' ' << centroids[1] << '\n';

        int centroid1 = centroids[0];
        int centroid2 = centroids[1];

        dfs(centroid1, centroid2);

        cout << ref << ' ' << ref2 << '\n';
        cout << ref << ' ' << centroid2 << '\n';
    }

    clearAll();
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }
}