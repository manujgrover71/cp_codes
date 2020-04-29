#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define ll long long

void solve(){
    int n; cin >> n;
    vector< pair<int, int> > v;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end());
    string ans = "";
    int currX = 0, currY = 0;
    for(auto i : v){
        while(currX < i.first) {
            currX++;
            ans += 'R';
        }
        while(currY < i.second){
            currY++;
            ans += 'U';
        }
        if(currX > i.first || currY > i.second) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n" << ans << '\n';
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