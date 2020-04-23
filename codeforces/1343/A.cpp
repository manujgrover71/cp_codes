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
    ll sum = 1;
    for(int i = 1;  ; i++){
        sum += pow(2, i);
        if(n % sum == 0){
            cout << n / sum << '\n';
            return;
        }
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
    while(t--)
        solve();
}