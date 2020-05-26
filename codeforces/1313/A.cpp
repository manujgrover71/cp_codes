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
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a+3, greater<int> ());
    int ans = 0;
    
    for(int i = 0; i < 3; i++){
        if(a[i]) ans++, --a[i];
    }
    
    for(int i = 0; i < 3; i++){

        if(a[i%3] && a[(i+1)%3]){
            ans++, --a[i], --a[(i+1)%3];
        }
    }

    if(a[0] && a[1] && a[2]) ans++;

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