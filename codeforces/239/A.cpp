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
    int y, k, n;
    cin >> y >> k >> n;
    int cnt = 0;
    for(int i = k; i <= n ; i += k){
        if(i > y && i <= n){
            cout << (i - y) << ' ';
            cnt++;
        }
    }
    if(cnt == 0) cout << "-1";
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