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

    int arr[n+1];

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    ll start = n;
    int i = 1, j = n;
    while(start != 0) {

        if(arr[i] == start) {
            start--;
            i++;
        }else if(arr[j] == start) {
            start--;
            j--;
        }else if(j - i > 1){
            cout << "YES\n";
            cout << i << ' ';
            for(int k = i+1; k < j; k++) {
                if(arr[k] > arr[i] && arr[k] > arr[j]) {
                    cout << k << ' ';
                    break;
                }
            }
            cout << j << '\n';
            return;
        }
    }

    cout << "NO\n";
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