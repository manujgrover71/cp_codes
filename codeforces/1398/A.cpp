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

void solve() {
    int n;
    cin >> n;
    vector<pair<ll, ll> > v;

    for(int i = 0; i < n; i++) {
        int t; cin >> t;
        v.pb({t, i+1});
    }

    sort(all(v));

    ll first = v[0].first;
    ll second = v[1].first;
    ll third = v[v.size()-1].first;

    if(third >= first + second) {
        vector<ll> ref;
        ref.pb(v[0].second);        
        ref.pb(v[1].second);        
        ref.pb(v[v.size() - 1].second);        

        sort(all(ref));

        cout << ref[0] << ' ' << ref[1] << ' ' << ref[2] << '\n';
    }else cout << "-1\n";
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
