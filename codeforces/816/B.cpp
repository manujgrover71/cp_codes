#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <set>
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
    int n, k, q;
    cin >> n >> k >> q;

    int arr[200001] = {0};

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;

        arr[a]++;
        if(b < 200000)
            arr[b+1]--;
    }

    vi ref;

    for(int i = 1; i <= 200000; i++){
        arr[i] += arr[i-1];
        if(arr[i] >= k) ref.pb(i);
    }

    while(q--){
        int l, r, ans = 0;
        cin >> l >> r;
        
        cout << (upper_bound(ref.begin(), ref.end(), r) - lower_bound(ref.begin(), ref.end(), l)) << '\n';

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