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

int n, m, k, visCount;
char arr[501][501];
bool vis[501][501];

void dfs(int x, int y, int empty) {

    if(x < 0 || x > n-1 || y < 0 || y > m-1) return;

    if(arr[x][y] == '#' || vis[x][y]) return;

    if(visCount < empty - k) visCount++;
    else {
        arr[x][y] = 'X';
    }

    vis[x][y] = true;

    dfs(x + 1, y, empty);
    dfs(x - 1, y, empty);
    dfs(x, y + 1, empty);
    dfs(x, y - 1, empty);

}

void solve() {
    cin >> n >> m >> k;
    int empty = 0, startX = -1, startY = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == '.') {
                if(startX == -1) startX = i, startY = j;
                empty++;
            }
        }
    }

    dfs(startX, startY, empty);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << arr[i][j];
        }
        cout << "\n";
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