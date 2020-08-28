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

int n, m;
string grid[101];
bool vis[101][101];
int col[101][101];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.' && !vis[x][y];
}

void dfs(int x, int y, int c) {

    col[x][y] = c;
    vis[x][y] = true;

    for(int i = 0; i < 4; i++) {
        if(isValid(x + dx[i], y + dy[i])) {
            dfs(x+dx[i], y + dy[i], c^1);
        }
    }

}

// Check for number of Cases!!
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && grid[i][j] == '.') {
                dfs(i, j, 0);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '.') {
                if(col[i][j]) cout << "B";
                else cout << "W";
            }else cout << grid[i][j];
        }
        cout << '\n';
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