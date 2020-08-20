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

// Check for number of Cases!!
void solve() {
    int n;
    string str;
    cin >> n >> str;

    map<string, int> mp;

    for(int i = 0; i < n-1; i++) {
        // if(i+1 < n)
        string ref = str.substr(i, 2);
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if(str.substr(j, 2) == ref) cnt++;
        }
        mp[ref]++;
    }

    int mx = 0;

    string ans = "";

    for(auto i : mp) {
        if(i.second > mx) {
            ans = i.first;
            mx = i.second;
        }
    }

    cout << ans << '\n';

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