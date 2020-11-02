#include <bits/stdc++.h>

using namespace std;

#define ll long long


// Check for number of Cases!!
void solve() {
    ll n; cin >> n;

    ll ref = 2*n;

    for(int i = n; i < ref; i++) {
        cout << (i * 2) << ' ';
    }

    cout << '\n';
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }
}