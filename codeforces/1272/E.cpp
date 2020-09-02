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

const ll mx = 2e5 + 5;
const ll INF = 1e9;
ll n;
vector<ll> adj[mx];
vector<ll> dis(mx, INF);

void dfs(vector<ll>& first, vector<ll>& second, vector<ll>& ans) {
    vector<ll> dis(n, INF);

    queue<ll> q;

    for(auto i : first) {
        dis[i] = 0;
        q.push(i);
    }

    while(!q.empty()) {

        ll top = q.front();
        q.pop();

        for(auto child : adj[top]) {
            if(dis[child] == INF) {
                dis[child] = dis[top] + 1;
                q.push(child);
            }
        }
    }

    for(auto i : second) {
        if(dis[i] != INF) {
            ans[i] = dis[i];
        }
    }
}

// Check for number of Cases!!
void solve() {
    cin >> n;
    vector<ll> odd, even;

    vector<ll> arr(n);

    for(ll i = 0; i < n; i++) {
        cin >> arr[i];

        if(arr[i] & 1) odd.pb(i);
        else even.pb(i);
    }

    for(ll i = 0; i < n; i++) {
        if((i - arr[i]) >= 0) adj[i - arr[i]].pb(i);
        if((i + arr[i]) < n) adj[arr[i] + i].pb(i);
    }

    vector<ll> ans(n, -1);

    dfs(even, odd, ans);
    dfs(odd, even, ans);

    for(auto i : ans) {
        cout << i << ' ';
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