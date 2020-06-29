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
    int n; cin >> n;
    vector<pair<int, int> > v;
    int mx = -1;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        mx = max(mx, x);
        v.pb({x, i});
    }

    sort(all(v));

    vi a, b;
    ll sumA = 0, sumB = 0;

    for(int i = 0; i < v.size(); i++) {
        if(i & 1) b.pb(v[i].second);
        else a.pb(v[i].second);
    }

    cout << a.size() << '\n';
    for(auto i : a) cout << i << ' ';
    cout << '\n' << b.size() << '\n';
    for(auto i : b) cout << i << ' ';

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