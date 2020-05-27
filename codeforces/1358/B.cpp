#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define ll long long

void solve(){
    int n; cin >> n;
    int arr[n+1];
    for(int i = 1; i <= n; i++) cin >> arr[i];

    sort(arr+1, arr + n+1);
    int cnt = 0;
    
    for(int i = n; i > -1; i--){
        if(arr[i] <= i){
            cout << i+1 << '\n';
            return;
        }
    }


    cout << 1 << '\n';
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