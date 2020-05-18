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
    string str; cin >> str;
    ll _min = 3e5;
    bool check1 = false, check2 = false, check3 = false;
    int last1 = _min, last2 = _min, last3 =_min;
    ll ans = _min;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '1'){
            last1 = i;
            check1 = true;
        }else if(str[i] == '2'){
            last2 = i;
            check2 = true;
        }else {
            last3 = i;
            check3 = true;
        }

        if(check1 && check2 && check3){
            ans = min(ans, i - (ll)min({last1, last2, last3}) + 1);
        }
    }
    if(ans == _min){
        cout << "0\n";
    }else cout << ans << '\n';
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