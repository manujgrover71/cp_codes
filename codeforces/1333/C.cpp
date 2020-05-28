#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <unordered_map>

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

void solve(){
    ll n; cin >> n;
    ll arr[n], prefix[n+1] = {0};
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        prefix[i+1] = prefix[i]+arr[i];
    }
    ll ans = 0;
    
    set<ll> s = {0};

    int start = 0, end = 0;

    while(start < n){
        while(end < n && !s.count(prefix[end + 1])){
            ++end;
            s.insert(prefix[end]);
        }

        ans += end - start;
        s.erase(prefix[start]);
        ++start;
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