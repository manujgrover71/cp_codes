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
#define rall(x) (x).rbegin(),(x).rend()
#define ll long long
#define mod 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pb push_back

// D R U L
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

const int mx = 1e6 + 5;
const int INF = mod;

ll power(int x, unsigned int y){
    ll res = 1;
    while(y > 0){
        if(y & 1) res = res * x;
        y >>= 1;
        x *= x;
    }
    return res;
}



// Check for number of Cases!!
void solve() {
    int n; cin >> n;

    vector<ll> one, two, three;

    for(int i = 0; i < n; i++) {
        ll temp; cin >> temp;
        one.pb(temp);
    }

    sort(all(one));

    for(int i = 0; i < n-1; i++) {
        ll temp; cin >> temp;
        two.pb(temp);
    }

    sort(all(two));

    ll ans = -1;

    for(int i = 0; i < n-1; i++) {
        if(one[i] != two[i]) {
            ans = one[i];
            break;
        }
    }

    if(ans == -1) cout << one[n-1];
    else cout << ans;
    cout << '\n';

    ans = -1;

    for(int i = 0; i < n-2; i++) {
        ll temp; cin >> temp;
        three.pb(temp);
    }

    sort(all(three));

    for(int i = 0; i < n-2; i++) {
        if(two[i] != three[i]) {
            cout << two[i];
            return;
        }
    }

    cout << two[n-2];

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }
}