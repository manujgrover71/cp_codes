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
    int n, k;
    cin >> n >> k;
    string str; cin >> str;

    set<char> st;

    for(int i = 0; i < k; i++){
        char a; cin >> a;
        st.insert(a);
    }

    ll ans = 0;
    ll ref = 0;

    for(int i = 0; i < n; i++) {
        
        if(st.count(str[i])) {
            ref++;
        }else {
            if(ref > 1) ans += ref * (ref + 1) / 2;
            else if(ref == 1) ans++;
            
            ref = 0;
        }
    }

    if(ref > 1) ans += ref * (ref + 1) / 2;
    else if(ref == 1) ans++;
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