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
    ll a, b, c, r;
    cin >> a >> b >> c >> r;

    ll total = abs(a - b);

    ll left = c - r;
    ll right = c + r;

    if(a > b) swap(a, b);
    if(a > right || b < left){
        cout << total << "\n";
    }
    else if(a <= left && right <= b){
        cout << total - abs(right - left) << '\n';
    }
    else if(left <= a && right >= b){
        cout << "0\n";
    }
    else if(a > left && b >= left && b >= right){
        cout << total - abs(right - a) << '\n';
    }
    else if(a < left && b >= left && right >= b ){
        cout << total - abs(b - left) << '\n';
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