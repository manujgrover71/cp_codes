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
        ll n, k;
        cin >> n >> k;
        ll x = k / (n-1);
        if( (x + k) % n == 0 ){
            cout << k + x - 1 << '\n';
        }else{
            cout << x + k << '\n';
        }

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