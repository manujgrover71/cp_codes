#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define all(x) (x).begin(),(x).end()
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

void solve() {
    int n; cin >> n;
    string str; cin >> str;

    vector<char> v;
    int zero = -1, one = INT_MAX;
    for(int i = n-1; i > -1; i--) {
        if(str[i] == '0') zero = max(zero, i);
        else if(str[i] == '1') one = min(one, i);
    }



    if(zero > one) {
        for(int i = 0; i < one; i++) {
            cout << str[i];
        }
        for(int i = zero; i < n; i++)
            cout << str[i];
    }else cout << str;
    cout << '\n';
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