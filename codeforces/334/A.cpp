    #include <algorithm>
    #include <iostream>
    #include <climits>
    #include <cstring>
    #include <string>
    #include <vector>
    #include <cmath>
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
        int start = 1, end = n*n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n/2; j++){
                cout << start++ << ' ' << end-- << ' ';
            }
            cout << '\n';
        }
    }

    int main(){

        #ifndef ONLINE_JUDGE
        freopen("/ATOMCODES/input.txt", "r", stdin);
        freopen("/ATOMCODES/output.txt", "w", stdout);
        #endif

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        solve();

    }