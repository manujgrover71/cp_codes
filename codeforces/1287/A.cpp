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
    string str; cin >> str;
    int ans = 0;
    while(true){
        bool check = false;
        for(int i = 1; i < n; i++){
            if(str[i-1] == 'A' && str[i] == 'P') {
                str[i] = 'A';
                check = true;
                i++;
            }
        }
        if(!check) break;
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
    while(t--){
        solve();
    }
}   