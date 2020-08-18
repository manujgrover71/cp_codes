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
    string str; cin >> str;

    bool same = true;

    for(int i = 1; i < n; i++) {
        if(str[i] != str[0]) {
            same = false;
            break;
        }
    }

    if(same) {
        cout << (n+2)/3 << '\n';
    }else {

        vector<int> ref;

        int last = 0;
        int cnt = 1;
        for(int i = 1; i < n; i++) {
            if(str[i] == str[last]) {
                cnt++;
            }else {
                ref.pb(cnt);
                last = i;
                cnt = 1;
            }
        }

        if(str[0] == str[n-1]) {
            ref[0] += cnt;
        }else ref.pb(cnt);

        int ans = 0;

        for(int i : ref) {
            ans += i / 3;
        }   

        cout << ans << '\n';

    }
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