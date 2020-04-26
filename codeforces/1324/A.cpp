#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define ll long long

void solve(){
    int n; cin >> n;
    int arr[n];
    int _max = INT_MIN;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        _max = max(_max, arr[i]);
    }
    for(int i = 0; i < n; i++){
        if((_max - arr[i]) % 2 != 0){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}