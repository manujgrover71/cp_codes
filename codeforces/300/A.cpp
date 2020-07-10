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
    vector<int> neg, pos, zero;

    for(int i = 0; i < n; i++) {
        int temp; cin >> temp;

        if(temp < 0 && neg.empty()) {
            neg.pb(temp);
            continue;
        }

        if(temp > 0) {
            pos.pb(temp);
            // continue;
        }else {
            zero.pb(temp);
        }

    }

    if(pos.empty()) {
        sort(all(zero), greater<int>());
        for(int i = 0; i < 2; i++) {
            int x = zero.back();
            zero.pop_back();
            pos.pb(x);
        }
    }

    cout << neg.size() << ' ';
    for(auto i : neg) cout << i << ' ';
    cout << '\n';

    cout << pos.size() << ' ';
    for(auto i : pos) cout << i << ' ';
    cout << '\n';

    cout << zero.size() << ' ';
    for(auto i : zero) cout << i << ' ';
    cout << '\n';

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