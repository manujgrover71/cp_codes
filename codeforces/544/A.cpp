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
    int t; cin >> t;
    string str; cin >> str;

    if(t > str.length()) {
        cout << "NO";
        return;
    }

    if(t == 1) cout << "YES\n" << str;
    else {
        set<char> ref;
        vi ans;
        ll count = 0;
        for(int i = 0; i < str.length(); i++) {
            if(!ref.count(str[i])) {
                ref.insert(str[i]);
                ans.pb(i);
                count++;
            }
            if(count == t) break;
        }

        if(count != t) {
            cout << "NO";
        }else {
            cout << "YES\n";
            for(int i = 0; i < ans.size(); i++) {
                if(i+1 < ans.size()) {
                    for(int j = ans[i]; j < ans[i+1]; j++) {
                        cout << str[j];
                    }
                }
                else {
                    for(int j = ans[i]; j < str.length(); j++) {
                        cout << str[j];
                    }
                }
                cout << '\n';
            }
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

    int t; t = 1;
    while(t--){
        solve();
    }

}