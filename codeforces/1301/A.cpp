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
    string a, b, c;
    cin >> a >> b >> c;

    for(int i = 0; i < a.length(); i++){
        if(a[i] != b[i]){
            if(a[i] != c[i] && c[i] != b[i]){
                cout << "NO\n";
                return;
            }
        }else{
            if(a[i] != c[i]){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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