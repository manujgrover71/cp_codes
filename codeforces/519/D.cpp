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
    ll nums[26] = {0};

    for(int i = 0; i < 26; i++) {
        cin >> nums[i];
    }

    string str; cin >> str;

    ll n = str.length();

    map<char, vector<ll>> mp;

    ll prefix[n] = {0};

    prefix[0] = nums[str[0] - 'a'];

    for(int i = 1; i < str.length(); i++) {
        prefix[i] = prefix[i-1] + nums[str[i] - 'a'];
    }

    // for(int i = 0; i < n; i++) {
    //     cout << prefix[i] << ' ';
    // }
    // cout << '\n';
    // return;

    for(int i = 0; i < n; i++) {
        mp[str[i]].pb(i);
    }

    // for(auto i : mp['a']) {
    //     cout << i << ' ';
    // }

    // return;

    ll ans = 0;

    for(int j = 0; j < 26; j++) {

        vector<ll> arr = mp[char(j + 'a')];

        if(arr.size() < 2) continue;

        map<ll, ll> ref;
        int last = -1;

        last = arr[0];
        ref[prefix[arr[0]]]++;
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i]-1 >= 0) {
                if(ref[prefix[arr[i]-1]])
                    ans += ref[prefix[arr[i]-1]];
                else if(arr[i] - 1 == last) ans++;
            } 
            last = arr[i];
            ref[prefix[arr[i]]]++;
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
    
    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }
}