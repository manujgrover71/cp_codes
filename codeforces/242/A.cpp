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
    int x, y, a, b;
    cin >> x >> y >> a >> b;

    vector<pair<int, int> > vc;

    for(int i = a; i <= x; i++) {
        for(int j = b; j <= min(x,y); j++) {
            if(i > j) vc.pb({i ,j});
        }
    }

    sort(all(vc));
    cout << vc.size() << '\n';
    for(auto i : vc) {
        cout << i.first << ' ' << i.second << '\n';
    }

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