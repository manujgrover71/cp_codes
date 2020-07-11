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

char change(char ch) {
    if(ch == 'B') return 'W';
    
    return 'B';
}

void solve() {
    int n; cin >> n;
    string str; cin >> str;

    char start;

    vi ans;
    ll b = 0, w = 0;
    for(int i = 0; i < n; i++) {
        if(str[i] == 'B') b++;
        else w++;
    }

    if(!b || !w) {
        cout << "0";
        return;
    }

    start = 'B';

    for(int i = 0; i < n-1; i++) {
        if(str[i] != start) {
            ans.pb(i+1);
            str[i] = change(str[i]);
            str[i+1] = change(str[i+1]);
        }
    }

    bool check = true;

    for(int i = 0; i < n-1; i++) {
        if(str[i] != str[i+1]) {
            check = false;
            break;
        }
    }

    if(!check) {

        start = 'W';

        for(int i = 0; i < n-1; i++) {
            if(str[i] != start) {
                ans.pb(i+1);
                str[i] = change(str[i]);
                str[i+1] = change(str[i+1]);
            }
        }

        for(int i = 0; i < n-1; i++) {
            if(str[i] != str[i+1]) {
                cout << "-1";
                return;
            }
        }
    
    }

    cout << ans.size() << '\n';

    for(auto i : ans) {
        cout << i <<  ' ';
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