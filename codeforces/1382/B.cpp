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

void solve(){
    int n;
    cin >> n;
    ll arr[n];
    bool check = 1;
    for(int i = 0; i < n; i++){
        cin >> arr[i];

        if(arr[i]==1) {
            check=0;
        }
    }
    int i=0;

    while( i < n && arr[i]==1){
        i++;
    }
    if(i==n){
        if(n%2) {
            cout << "First\n";
            return;
        }
        else {
            cout << "Second\n";
            return;
        }
    }
    if(i%2) {
        cout << "Second\n";
            return;
    }
    else {
        cout << "First\n";
        return;
    }


}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        solve();
    }

}