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

const int mx = 1e5 + 5;
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


int nodes, currColor;
vector<int> adj[mx];
vector<int> color(mx);
bool ok;

void dfs(int curr, int par) {

    ok = (ok && (color[curr] == currColor));

    if(!adj[curr].size()) return;

    for(auto child : adj[curr]) {
        if(child != par) {
            dfs(child, curr);
        }
    }

}

bool check(int curr) {

    bool ans = true;

    if(!adj[curr].size()) return ans;

    for(auto child : adj[curr]) {

        currColor = color[child];

        ok = true;

        dfs(child, curr);
        ans = (ans && ok);
    }

    return ans;

}

// Check for number of Cases!!
void solve() {
    cin >> nodes;

    for(int i = 0; i < nodes-1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    for(int i = 0; i < nodes; i++) {
        cin >> color[i];
    }

    int root1 = -1, root2 = -1;

    for(int i = 0; i < nodes; i++) {
        for(auto child : adj[i]) {
            if(color[i] != color[child]) {
                root1 = i;
                root2 = child;
            }
        }
    }


    if(root1 == -1) {
        cout << "YES\n";
        cout << "1";
        return;
    }

    if(check(root1)) {
        cout << "YES\n";
        cout << root1+1;
    }else if(check(root2)) {
        cout << "YES\n";
        cout << root2+1;
    }else {
        cout << "NO";
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