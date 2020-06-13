#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>

using namespace std;

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
    int n, x;
    cin >> n >> x;
    set<int> s;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        s.insert(arr[i]);
    }
    ll ans = 0, check = 0, i = 1;
    while(true){
        if(s.count(i)){
            ans++;
        }else if (x--)
            ans++;
        else
            break;
        i++;
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

    int t; cin >> t;
    while(t--){
        solve();
    }

}