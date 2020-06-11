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
    int freq[1001] = {0};

    int n; cin >> n;
    int mx = -1;

    for(int i = 0; i < n; i++){
        int a; cin >> a;
        freq[a]++;
        mx = max(mx, a);
    }   
    int till = 0;
    for(int i = mx; i > -1; i--){
        if(freq[i] + till >= i){
            cout << i << '\n';
            return;
        }
        till += freq[i];
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