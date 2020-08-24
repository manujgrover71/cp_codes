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

// Check for number of Cases!!

string grid[1001];
vector<vector<ll>> dis(1000, vector<ll> (1000, 0)), vis(1000, vector<ll> (1000, 0));

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int x, int y) {

    queue<pair<int, int>> q;
    q.push({x, y});

    ll count = 0;
    vis[x][y] = true;
    while(!q.empty()) {
        int currX = q.front().first;
        int currY = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++) {
            int newX = currX + dx[i];
            int newY = currY + dy[i];
            if(grid[newX][newY] == '*') {
                count++;
                // vis[newX][newY] = true;
            }

            if(!vis[newX][newY] && grid[newX][newY] == '.') {
                vis[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }

    q.push({x, y});
    dis[x][y] = count;

    while(!q.empty()) {

        int currX = q.front().first;
        int currY = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++) {
            int newX = currX + dx[i];
            int newY = currY + dy[i];

            if(dis[newX][newY] != count && grid[newX][newY] == '.') {
                dis[newX][newY] = count;
                q.push({newX, newY});
            }
        }

    }

}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && grid[i][j] == '.') {
                bfs(i, j);
            }
        }
    }

    for(int i = 0; i < k; i++) {
        int x, y; cin >> x >> y;
        x--, y--;
        cout << dis[x][y] << '\n';
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