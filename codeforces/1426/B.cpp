#include <bits/stdc++.h>

using namespace std;
#define ll long long

// Check for number of Cases!!
void solve() {
    ll n, m;
    cin >> n >> m;

    int p = 0;

    for(int i = 0; i < n; i++) {
        int a1;
        int a2;
        int b1;
        int  b2;
        cin >> a1 >> a2 >> b1 >> b2;
        if(a2 == b1)
            p = 1;
    }

    if(m % 2 || !p) {
        cout << "NO\n";
    }else {
        cout << "YES\n";
    }
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