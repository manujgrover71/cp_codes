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

void solve() {
    int n; cin >> n;
    int arr[n+1];

    for(int i = 0; i < n; i++) cin >> arr[i];

    arr[n] = INT_MAX;

    bool check = false;
    int start = -1, end = -1;

    for(int i = 0; i < n; i++) {

        if(check) {
            if(arr[i] < arr[i+1]) {
                end = i;
                break;
            }
        }

        if(arr[i] > arr[i+1] && !check) {
            check = true;
            start = i;
        }
    }

    int i = start, j = end;

    while(i < j) {
        swap(arr[i], arr[j]);
        i++, j--;
    }

    for(int i = 0; i < n-1; i++) {
        if(arr[i] > arr[i+1]) {
            cout << "no";
            return;
        }
    }

    cout << "yes\n";
    if(start == -1) cout << "1 1";
    else cout << start+1 << ' ' << end+1;
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