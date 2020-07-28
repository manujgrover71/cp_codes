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
    ll n, k;
    cin >> n >> k;

    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int prefix[n];
    prefix[0] = arr[0];

    int last = arr[0], count = 0;
    for(int i = 1; i < n; i++) {
        if(arr[i] > prefix[i-1]) {
            prefix[i] = arr[i];
        }else {
            prefix[i] = prefix[i-1];
        }

        if(prefix[i] == last) {
            count++;
            if(count == k) {
                cout << last;
                return;
            }
        }else {
            last = prefix[i];
            count = 1;
        }

        if(prefix[i] == n) {
            cout << n;
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