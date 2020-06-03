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
    char arr[] = {'R', 'O', 'Y', 'G', 'B', 'I', 'V'};

    int n; cin >> n;
    // cout << n;
    string ans;

    for(int i = 0, j = -1; i < n; i++){
        if(i < 7) ans += arr[i];
        else {
            j++;
            ans += arr[3 + (j % 4)];
        }
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