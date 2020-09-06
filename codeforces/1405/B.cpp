#include <bits/stdc++.h>

using namespace std;

#define ll long long

void fun() {
    ll n; cin >> n;
    ll arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll MXN = 0;
    ll ref = 0;
    for(int i = n-1; i >= 0; i--) {
        ref += arr[i];
        MXN = max(MXN, ref);
    }   

    cout << MXN << '\n';
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