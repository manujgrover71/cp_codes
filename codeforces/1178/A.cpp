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
    int n; cin >> n;
    int arr[n];

    ll sum = 0;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    if(arr[0] > sum/2) {
        cout << "1\n1";
        return;
    }

    vi ans;
    ans.pb(1);
    ll curr = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] * 2 <= arr[0]) {
            ans.pb(i+1);
            curr += arr[i];
        }

        if(curr > sum/2) break;
    }

    if(curr > sum/2) {
        cout << ans.size() << '\n';
        for(auto i : ans) {
            cout << i << ' ';
        }
    }else cout << "0";
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