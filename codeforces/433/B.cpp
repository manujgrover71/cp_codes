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
    ll arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    ll preForOriginal[n], preForSorted[n];

    preForOriginal[0] = arr[0];
    for(int i = 1; i < n; i++) preForOriginal[i] = preForOriginal[i-1] + arr[i];

    sort(arr, arr+n);

    preForSorted[0] = arr[0];
    for(int i = 1; i < n; i++) preForSorted[i] = preForSorted[i-1] + arr[i];

    int q; cin >> q;

    while(q--){
        int type, l, r;
        cin >> type >> l >> r;
        l--, r--;
        if(type == 1){
            if(l)
                cout << preForOriginal[r] - preForOriginal[l-1];
            else cout << preForOriginal[r];
        }else{
            if(l)
                cout << preForSorted[r] - preForSorted[l-1];
            else cout << preForSorted[r];   
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