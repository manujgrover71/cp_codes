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
    int n, a;
    cin >> n >> a;
    a--;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int left = a, right = a;
    ll ans = 0;
    while(true){

        if(left == right) {
            if(arr[left]) ans++;
            left--, right++;
            continue;
        }

        if(left < 0 && right > n-1) break;

        if(left > -1 && right < n){
            
            if(arr[left] && arr[right]) ans+= 2;
        }
        else if(left > -1 && right > n-1 && arr[left]) ans++;
        else if(left < 0 && right < n && arr[right]) ans++;

        left--;
        right++;
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