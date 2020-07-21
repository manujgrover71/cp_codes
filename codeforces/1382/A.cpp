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
    int n, m;
    cin >> n >> m;

    int a[n], b[m];

    map<int, int> mp;
    set<int> st;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(!st.count(a[i])) {
            st.insert(a[i]);
            mp[a[i]]++;
        }
    }

    st.clear();

    for(int i = 0; i < m; i++) {
        cin >> b[i];
        if(!st.count(b[i])) {
            st.insert(b[i]);
            mp[b[i]]++;
        }
    }

    for(auto i : mp) {
        if(i.second > 1) {
            cout << "YES\n";
            cout << 1 << ' ' << i.first << '\n';
            return;
        }
    }

    cout << "NO\n";
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    // t = 1;
    while(t--){
        solve();
    }

}