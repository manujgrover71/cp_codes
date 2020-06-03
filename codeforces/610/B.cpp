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

    int n; cin >> n;
    ll arr[n];
    ll mn = 1e9;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        mn = min(mn, arr[i]);
    }
    
    vector<ll> ref;

    for(int i = 0; i < n; i++)
        if(arr[i] == mn) ref.pb(i);

    ll ans = n * mn;

    if(ref.size() != n) {

        ll extra = -1;

        for(int i = 0; i < ref.size(); i++){
            int a = ref[i];
            int b = ref[(i+1)%ref.size()];

            if(b > a){
                extra = max(extra, (ll)(b-a-1));
            }else{
                extra = max(extra, (ll)n - (a - b + 1));    
            }
        }
        ans += extra;
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