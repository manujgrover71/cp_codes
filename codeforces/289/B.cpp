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

void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    int size = (n * m);
    int arr[size];
    set<int> s;
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
        s.insert(arr[i] % d);
    }

    if(s.size() > 1) {
        cout << "-1";
        return;
    }

    sort(arr, arr + size);

    int x = arr[size/2];

    ll ans = 0;

    for(auto i : arr) {
        ans += abs(x - i);
    }

    ans /= d;

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