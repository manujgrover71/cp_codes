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

bool check(int n){
    int freq[10] = {0};
    while(n != 0){
        if(freq[n%10] == 0) freq[n%10]++;
        else return false;
        n /= 10;
    }
    return true;
}

void solve(){
    int l, r;
    cin >> l >> r;
    for(int i = l; i <= r; i++){
        if(check(i)){
            cout << i;
            return;
        }
    }
    cout << "-1";
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