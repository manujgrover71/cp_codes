#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define ll long long

ll addNum(ll num){
    ll temp = num, _max = 0, _min = INT_MAX;
    while(temp != 0){
        ll k = temp % 10;
        _max = max(_max, k);
        _min = min(_min, k);
        temp /= 10;
    }
    return (_max * _min);
}

void solve(){
    ll a, K;
    cin >> a >> K;

    ll ref = 0;
    while(--K){
        ref = addNum(a);
        if(ref == 0) break;
        a += ref;
    }
    cout << a << '\n';
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