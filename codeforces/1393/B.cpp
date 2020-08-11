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
    int n; cin >> n;
    vector<ll> count((int)1e5 + 1, 0);

    ll rect = 0, square = 0;

    for(int i = 0; i < n; i++) {
        int temp; cin >> temp;
        count[temp]++;
    }

    for(int i = 0; i < (int)1e5 + 1; i++) {
        int x = count[i];
        if(x) {
            square += x /4;
            x %= 4;
            rect += x / 2;
        }
    }

    int q; cin >> q;

    while(q--) {

        char ch;
        int num;
        cin >> ch >> num;

        int x = count[num];

        square -= x / 4;
        x %= 4;
        rect -= x / 2;

        if(ch == '+') {
            count[num]++;
        }else {
            count[num]--;
        }

        x = count[num];
        square += x / 4;
        x %= 4;
        rect += x / 2;

        if(square >= 2 || (square == 1 && rect >= 2)) {
            cout << "YES\n";
        }else cout << "NO\n";
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