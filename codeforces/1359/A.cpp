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
#define pb(x) push_back(x)

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
    int n, m, k;
    cin >> n >> m >> k;

    if(m == 0) {
        cout << "0\n";
        return;
    }

    int cards = n/k;
    int max;
    if(m <= cards){
        max = m;
        m = 0;
    }else if(m > cards){
        max = cards;
        m -= cards;
    }

    if(m){
        int max2 = (double)ceil((double)m / (double)(k-1.0));
        cout << max - max2 << '\n';
    }else cout << max << '\n';
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