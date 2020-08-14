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

    int n, m;
    cin >> n >> m;

    int arr[n], brr[m];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> brr[i];
    }

    for(int ans = 0; ans <= 1<<9; ans++) {

        bool check2 = true;

        for(int i = 0; i < n; i++) {
            bool check = false;
            for(int j = 0; j < m; j++) {
                if(((arr[i] & brr[j]) | ans) == ans) {
                    check = true;
                    break;
                }
            }
            if(!check) {
                check2 = false;
                break;
            }
        }

        if(check2) {
            cout << ans << '\n';
            return;
        }

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