#include <bits/stdc++.h>

using namespace std;

void solve() {

    int a[4];

    for(int i = 0; i < 4; i++)
        cin >> a[i];

    int Odds = 0, mnx = INT_MAX;

    for(int i = 0; i < 4; i++) {
        if(i < 3) {
            Odds += (a[i] & 1);
            mnx = min(a[i],mnx);
        }
    }

    if(a[3] % 2 == 0) {

        if((Odds == 3 && mnx >= 1) || Odds == 1 || Odds == 0) {
            cout << "YES\n";
            return;
        }

    }else {

        if(Odds == 0 || (Odds == 2 && mnx >= 1) || (Odds == 3 && mnx >= 1)) {
            cout << "YES\n";
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