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
    int n, d;
    cin >> n >> d;

    vector< pair<int, int> > arr;
    for(int i = 0; i < n; i++){
        int m, s;
        cin >> m >> s;
        arr.pb({m,s});
    }

    sort(arr.begin(), arr.end());
    ll ans = -1;
    int i = 0, j = 0;
    ll ref = 0;
    bool check = false;
    while(!check){
        check = true;
        while(j < arr.size() && arr[j].first - arr[i].first < d){
            ref += arr[j].second;
            j++;
        }
        ans = max(ans, ref);
        while(i < j && arr[j].first - arr[i].first >= d){
            ref -= arr[i].second;
            i++;
            check = false;
        }
       
    }

    cout << ans << '\n';
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