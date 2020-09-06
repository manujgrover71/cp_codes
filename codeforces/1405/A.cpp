#include <bits/stdc++.h>

using namespace std;

#define ll long long

void fun() {
    int n; cin >> n;
    ll arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    reverse(arr, arr + n);

    for(auto i : arr) {
        cout << i << ' ';
    }
    cout << '\n';
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while(t--) {
      fun();
    }
}