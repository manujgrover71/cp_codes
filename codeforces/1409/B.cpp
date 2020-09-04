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
    ll a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;

    ll ans = 0, ans2 = 0;

    // if((a - x - n) >= (b-y - n)) {
        ll ba = b;
        ll tempA = max(y, b - n);
        ll B = tempA;
        ll N = n;
        N -= (ba - tempA);
        ll A = a;
        if(N) {
            A = max(x, A - N);
        }
        // cout << A << ' ' << B << '\n';
        ans = A * B;
    // }else {

        ll ab = a;
        ll temp = max(x, a - n);
        a = temp;
        n -= (ab - temp);

        if(n) {
            b = max(y, b - n);
        }
        // cout << a << ' ' << b << '\n';
        // cout << a * b << '\n';
        ans2 = a * b;
    // }

    cout << min(ans, ans2) << '\n';

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }
}