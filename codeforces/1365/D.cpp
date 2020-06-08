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

ll power(int x, unsigned int y){
    ll res = 1;
    while(y > 0){
        if(y & 1) res = res * x;
        y >>= 1;
        x *= x;
    }
    return res;
}

int n, m;
char arr[51][51];
bool vis[51][51];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool isValid(int x, int y){

    if(x < 0 || x > n || y < 0 || y > m)
        return false;

    if(vis[x][y] || arr[x][y] == '#')
        return false;
    
    return true;

}

void dfs(int x, int y){

    vis[x][y] = true;

    for(int i = 0; i < 4; i++){
        if(isValid(x + dx[i], y + dy[i]))
            dfs(x + dx[i], y + dy[i]);
    }

}

void solve(){
    cin >> n >> m;
    int G = 0, B = 0;
    memset(vis, false, sizeof(vis));
    memset(arr, '#', sizeof(arr));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'B') B++;
            else if(arr[i][j] == 'G') G++;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 'B'){
                if(i-1 > -1 && arr[i-1][j] == '.')
                    arr[i-1][j] = '#';

                if(i + 1 < n && arr[i+1][j] == '.')
                    arr[i+1][j] = '#';

                if(j-1 > -1 && arr[i][j-1] == '.')
                    arr[i][j-1] = '#';

                if(j + 1 < m && arr[i][j+1] == '.')
                    arr[i][j+1] = '#';
            }
        }
    }

    if(arr[n-1][m-1] == '.'){
        dfs(n-1, m-1);
    }else if((arr[n-1][m-1] == '#' && !G)){
        cout << "Yes\n";
        return;
    }else {
        cout << "No\n";
        return;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if((arr[i][j] == 'B' && vis[i][j])){
                cout << "No\n";
                return;
            }
            if(arr[i][j] == 'G' && !vis[i][j]){
                cout << "No\n";
                return;
            }
        }
    }

    cout << "Yes\n";
    
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        solve();
    }

}