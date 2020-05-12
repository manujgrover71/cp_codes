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
    ll left, right, down, up;
    cin >> left >> right >> down >> up;

    ll x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;

    if(((x1 == x2 && x1 == x)  && (left || right)) || ((y1 == y2 && y1 == y) && (up || down))){
        cout << "NO\n";
        return;
    }

    ll result_lr = (left * -1) + right  + x;
    ll result_ud = up + (down * -1) + y;

    // cout << result_lr << ' ' << result_ud << '\n';

    if(result_lr >= x1 && result_lr <= x2 && result_ud >= y1 && result_ud <= y2){
        cout << "YES\n";
    }else cout << "NO\n";

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