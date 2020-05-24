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
    ll n, m;
    cin >> n >> m;
    ll last = 1, ans = 0;
    while(m--){
        ll a; cin >> a;

        if(a > last){
            ans += (a - last);
        }
        if(a < last){
            ans += (n - last + a);
        }
        last = a;
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