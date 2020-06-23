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
#define pk push_back

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
    string str; cin >> str;
    ll cb = 0, cc = 0, cs = 0;

    for(char i : str) {
        if(i == 'B') cb++;
        else if(i == 'C') cc++;
        else cs++;
    }

    ll nb, ns, nc; cin >> nb >> ns >>  nc;
    ll pb, ps, pc; cin >> pb >> ps >> pc;

    ll amount; cin >> amount;
    ll ans = 0;
    ll start = 0, end = 2e12;
    
    while(start <= end) {
        ll mid = (start + end)/2;
        ll now = max((ll)0, cb*mid - nb) * pb + max((ll)0, cc*mid - nc) * pc + max((ll)0, cs*mid - ns) * ps;
        if(now <= amount) {
            ans = max(ans, mid);
            start = mid + 1;
        }else {
            end = mid - 1;
        }
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