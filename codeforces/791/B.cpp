#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

#define ll long long
#define mod 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pb(x) push_back(x)

ll power(int x, unsigned int y){
    ll res = 1;
    while(y > 0){
        if(y & 1) res = res * x;
        y >>= 1;
        x *= x;
    }
    return res;
}

ll e, ve;

void dfs(int v, vi arr[], int vis[]){

    vis[v] = 1;
    e += arr[v].size();
    ve++;
    for(int child : arr[v]){
        if(!vis[child])
            dfs(child, arr, vis);
    }
}

void solve(){
    int nodes, edges;
    cin >> nodes >> edges;

    vi arr[nodes+1];
    int vis[nodes+1] = {0};

    while(edges--){
        int a, b;
        cin >> a >> b;
        arr[a].pb(b);
        arr[b].pb(a);
    }

    for(int i = 1; i <= nodes; i++){
        if(!vis[i]){
            e = 0, ve = 0;
            
            dfs(i, arr, vis);

            if(e != (ve*(ve-1))){
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

}