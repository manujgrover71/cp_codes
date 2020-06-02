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
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    ll ans = 0;
    for(int i = 0; i < n; i++){

        int j = i-1, k = i+1;
        ll ref = 0;
        while(j > -1){
            if(arr[j] > arr[j+1]) break;
            ref++;
            j--;
        }
        
        while(k < n){
            if(arr[k] > arr[k-1]) break;
            ref++;
            k++;
        }

        ans = max(ans, ref+1);
    }
    cout << ans;    
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