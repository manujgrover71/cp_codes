#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
#define ll long long

void solve(){
    int n, k;
    cin >> n >> k;
    int arr[n+1];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    unordered_map<ll, ll> zero_changes;
    vector< pair<ll, ll> > v;
    ll prefix[2*k + 30] = {0};

    for(int i = 0; i < n/2; i++){
        ll lower = min(arr[i], arr[n-i-1]);
        ll upper = max(arr[i], arr[n-i-1]);
        v.push_back({lower, upper});
    }

    for(auto pairs : v){
        zero_changes[pairs.first + pairs.second]++;
        prefix[pairs.first + 1]++;
        prefix[pairs.second + k + 1]--;
    }

    ll temp = 0;
    for(int i = 2; i <= 2*k ;i++){
        temp += prefix[i];
        prefix[i] = temp;
    }

    ll ans = n;

    for(int i = 2; i <= 2*k ;i++){
        ll count0 = zero_changes[i];
        ll count1 = prefix[i] - count0;
        ll count2 = (n/2) - count1- count0;

        ll total = 0 * count0 + 1 * count1 + 2 * count2;

        ans = min(ans, total);
    }

    cout << ans << "\n";

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}