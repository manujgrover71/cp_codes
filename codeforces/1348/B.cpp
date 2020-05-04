#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define ll long long

void solve(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    set<int> s;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }
    if(s.size() > k) {
        cout << "-1\n";
        return;
    }
    else{
        cout << n*k << '\n';
        for(int i = 0; i < n; i++){
            for(auto j : s) cout << j << ' ';
            for(int j = 0; j < k - s.size(); j++)
                cout << 1 << ' ';
        }
    }
    cout << '\n';
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