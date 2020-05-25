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
    int n, k;
    cin >> n >> k;

    if(k >= n){
        cout << "1\n";
        return;
    }
    
    ll ans = 1e9;

    vector<int> factors;

    for (int i=1; i<=sqrt(n) && i <= k; i++) { 
        if (n%i == 0) { 
            if (n/i == i && (i) <= k) 
                factors.emplace_back(n/i);
            else {
                if(i <= k){
                    factors.emplace_back(i);
                }
                if((n/i) <= k) factors.emplace_back(n/i);
            }
        } 
    } 

    for(auto i: factors){
        ans = min(ans, (ll)(n/i));
    }

    cout << ans << '\n';
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