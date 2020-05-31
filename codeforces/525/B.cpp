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
    string str; cin >> str;
    int q; cin >> q;
    int arr[str.length()/2] = {0};

    while(q--){
        int a; cin >> a;
        a--;
        arr[a]++;
    }

    for(int i = 1; i < str.length()/2; i++){
        arr[i] += arr[i-1];
    }

    for(int i = 0; i < str.length()/2; i++){
        if(arr[i] & 1){
            swap(str[i], str[str.length() - 1 - i]);
        }
    }

    cout << str;
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