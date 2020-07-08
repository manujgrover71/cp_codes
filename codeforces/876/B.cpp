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

void solve() {

    int n, k, m;
    cin >> n >> k >> m;

    map<ll, vector<ll>> mp;

    for(int i = 0; i < n; i++) {
        ll temp; cin >> temp;
        mp[temp%m].pb(temp);
    }

    for(auto i : mp) {
        if(i.second.size()) {
             if(i.second.size() >= k) {
                 ll count = 0;
                 cout << "Yes\n";
                 for(int j = 0; j < mp[i.first].size() && count < k; j++) {
                     cout << mp[i.first][j] << ' ';
                     count++; 
                 }
                 return;
             }
             mp[i.first].clear();
        }
    }
    cout << "No";
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