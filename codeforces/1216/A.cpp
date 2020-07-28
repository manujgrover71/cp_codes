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
    if(ch == 'a')
        return 'b';
    return 'a';
}

void solve() {
    int n; cin >> n;

    string str; cin >> str;

    int ans = 0;

    for(int i = 0; i < n; i+=2) {
        char f = str[i];
        char s = str[i+1];

        if(f == s) {
            str[i] = change(f);
            ans++;
        }
    }

    cout << ans << '\n' << str;
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