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
#define pb push_back

bool dfs(int src, int des, int vis[], int color, vector< pair<int,int> > arr[]){

    vis[src] = 1;

    if(src == des) return true;

    for(auto child : arr[src]){
        if(child.second == color && !vis[child.first]){
            if(dfs(child.first, des, vis, color, arr)){
                return true;
            }
        }
    }

    return false;

}

void solve(){
    int nodes, edges;
    cin >> nodes >> edges;

    vector< pair<int, int> > arr[nodes+1];

    while(edges--){
        int a, b, c;
        cin >> a >> b >> c;
        arr[a].pb({b,c});
        arr[b].pb({a,c});
    }

    int q; cin >> q;
    while(q--){
        int src, des;
        cin >> src >> des;

        ll ans = 0;
        for(int i = 1; i <= 100; i++){
            int vis[102] = {0};
            if(dfs(src, des, vis, i, arr)) 
                ans++;
        }

        cout << ans << '\n';
    }
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