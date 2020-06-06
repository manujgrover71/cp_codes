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
    ll n; cin >> n;

    vector< pair<ll, ll> > v;

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v.pb({a, b});
    }

    sort(v.begin(), v.end());
    ll last = 0;
    for(int i = 0; i < n; i++){
        if(last <= v[i].second)
            last = v[i].second;
        else last = v[i].first;
    }

    cout << last;
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