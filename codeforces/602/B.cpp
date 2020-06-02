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

    int lastPos = 0;
    int lastDiff = 0;
    int diff[n] = {0};

    for(int i = 1; i < n; i++)
        diff[i] = arr[i] - arr[i-1];

    ll ans = 0;
    ll l = 0;
    for(int i = 1; i < n; i++){
        if(diff[i] != 0){
            if(lastDiff == diff[i]){
                ans = max(ans, (ll)i - l);
                l = lastPos;
                lastPos = i;
            }
            else{
                lastDiff = diff[i];
                lastPos = i;
            }
        }
    }

    cout << max(ans, (ll)n - l);
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