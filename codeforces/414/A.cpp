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
    ll n, k;
    cin >> n >> k;

    ll canHave = n/2;

    if(n == 1 && k == 0) {
        cout << "1";
        return;
    }else if(n == 1) {
        cout << "-1";
        return;
    }

    if(k >= canHave) {
        ll count = 1;
        ll ref = k - (n/2) + 1;
        cout << ref << " " << ref * 2 << " ";
        n -= 2;
        while(n--) {
            
            while(count == ref || count == ref * 2) ++count;
            
            cout << count << ' ';
            
            count++;
        }

    }else cout << "-1\n";
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