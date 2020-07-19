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

void solve(){
    ll l,r,m;

    cin >> l >> r >> m;
    
    for(int i = l; i <= r; i++){
        if(m % i== 0){
            cout << i << ' ' << r << " " << r << "\n";
            return ;
        }
    }
    
    for(int i = l; i <= r; i++){
        ll xr = r - i;
        
        ll xrc = m - xr;
        
        ll k = l;

        while(xrc / k >= 1 && k <= r){
            if(xrc % k == 0){
                cout<< k << " " << r << " " << i << "\n";
                return ;
            }
            k++;
        }
        xrc = m - ( i - r );
        k = l;
        while(xrc / k >= 1 && k <= r){
            if(xrc % k==0){
                cout << k << " " << i << " " << r << "\n";
                return ;
            }
            k++;
        }
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