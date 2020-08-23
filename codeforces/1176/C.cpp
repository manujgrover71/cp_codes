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
#define rall(x) (x).rbegin(),(x).rend()
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

// Check for number of Cases!!
void solve() {
    ll n;
    cin >> n;

    ll arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }   

    if(n < 6) {
        cout << n << '\n';
        return;
    }

    int next4 = 0, next8 = 0, next15 = 0, next16 = 0, next23 = 0, next43 = 0;

    int extras = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] == 4) {
            next4++; 
        }else if(arr[i] == 8) {
            if(next4 > 0) {
                next4--;
                next8++;
            }else extras++;
        }else if(arr[i] == 15) {
            if(next8 > 0) {
                next8--;
                next15++;
            }else extras++;
        }else if(arr[i] == 16) {
            if(next15 > 0) {
                next15--;
                next16++;
            }else extras++;
        }else if(arr[i] == 23) {
            if(next16 > 0) {
                next16--;
                next23++;
            }else extras++;
        }else {
            if(next23) {
                next23--;
            }else extras++;
        }
    }

    extras += next4 + (2 * next8) + (3 * next15) + (4 * next16) + (5 * next23);
    cout << extras << '\n';
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }
}