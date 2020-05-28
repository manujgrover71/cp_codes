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
#define pb(x) push_back(x)

ll power(int x, unsigned int y){
    ll res = 1;
    while(y > 0){
        if(y & 1) res = res * x;
        y >>= 1;
        x *= x;
    }
    return res;
}

void solve(){
    int n; cin >> n;
    int a[n], b[n];
    vector< pair<int, int> > v;
    bool pos = false, neg = false;
    for(int i = 0; i < n; i++){
       cin >> a[i];
       if(a[i] == -1){
           neg = true;
       }else if(a[i] == 1) pos = true;
       v.push_back({pos, neg});
    }
        
    for(int i = 0; i < n; i++) cin >> b[i];

    if(a[0] != b[0]) {
        cout << "NO\n";
        return;
    }
    else{
        for(int i = 1; i < n; i++){
            if(a[i] != b[i]){
                ll x = a[i] - b[i];
                if(x < 0 && !v[i-1].first || x > 0 && !v[i-1].second){
                    cout << "NO\n";
                    return;
                }
            }
        }
        cout << "YES\n";
    }
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