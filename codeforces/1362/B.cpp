#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>

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

void solve(){
    int n; cin >> n;

    set<int>  ref;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        ref.insert(arr[i]);
    }

    for(int i = 1; i <= 1024; i++){
        set<int> r;
        r.clear();
        for(int j = 0; j < n; j++){
            r.insert(arr[j] ^ i);
        }
        if(r == ref) {
            cout << i << '\n';
            return;
        }
    }

    cout << "-1\n";
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