#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
#define ll long long

void solve(){
    int n, k; cin >> n >> k;
    map<int, pair<int, int> > m;

    for(int i = 0; i < k; i++){
        int a, b, deb;
        cin >> a >> b >> deb;

        m[a].first += deb;
        m[b].second += deb;
    }
    ll ans = 0;
    for(auto i: m){
        if(i.second.first == 0 && i.second.second != 0){
            ans += i.second.second;
        }
        else if(i.second.first < i.second.second ){
            // int _min = min(i.second.first, i.second.second);
            ans += i.second.second - i.second.first;
        }
    }
    cout << ans;
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