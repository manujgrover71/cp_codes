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
    ll leftSum = 0, rightSum = 0;

    ll arr[n];
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(!i) leftSum += arr[i];
        else rightSum += arr[i];
    }

    if(n == 1) {
        cout << "0";
        return;
    }
    
    ll ans = leftSum == rightSum;

    for(int i = 1; i < n-1; i++) {
        leftSum += arr[i];
        rightSum -= arr[i];
        ans += (leftSum == rightSum);
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