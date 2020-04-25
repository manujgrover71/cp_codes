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
    int arr[n];
    
    for(int i = 0; i < n; i++) cin >> arr[i];
    int mx = arr[0], ref = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] > mx) mx = arr[i];
        else ref = max(ref, mx-arr[i]);
    }
    int ans = 0;
    while(ref){
        ref = ref/2;
        ans++;
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
    while(t--)
        solve();
}