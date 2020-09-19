#include <bits/stdc++.h>

using namespace std;

// Check for number of Cases!!
void solve() {
    int n; cin >> n;

    string str; 
    cin >> str;

    int o_a = 0, e_a = 0;

    for(int i = 0; i < n; i += 2) {
        if((str[i] - '0') & 1) {
            o_a++;
        }
    }

    int o_b = 0, e_b = 0;

    for(int i = 1; i < n; i += 2) {
        if((str[i] - '0') % 2 == 0) {
            e_b++;
        }
    }

    if(n % 2 == 0) {

        if(e_b) {
            cout << "2\n";
        }else {
            cout << "1\n";
        }

    }else {
        if(o_a) {
            cout << "1\n";
        }else {
            cout << "2\n";
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
    
    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }
}