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
    ll n; cin >> n;

    map<ll, ll> mp;

    ll arr[n];

    ll count = 0, last = -1;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]] = mp[arr[i] - 1] + 1;
        if(mp[arr[i]] > count) {
            count = mp[arr[i]];
            last = arr[i];
        } 
    }

    vector<ll> ans;

    for(int i = n-1; i >= 0; i--) {
        if(arr[i] == last) {
            ans.pb(i+1);
            last--;
        }
    }

    cout << ans.size() << '\n';
    for(int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << ' ';
    }
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