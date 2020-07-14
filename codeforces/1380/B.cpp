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

char help(char ch) {
    switch(ch) {
        case 'R' : return 'P';
        case 'S' : return 'R';
        case 'P' : return 'S';
    }

    return 'R';
}

void solve() {

    string str; cin >> str;

    ll r = 0, s = 0, p = 0;

    for(int i = 0; i < str.length(); i++) {
        if(str[i] == 'R') r++;
        else if(str[i] == 'S') s++;
        else p++;
    }

    char ch;

    if(r >= s && r >= p) ch = 'R';
    else if(s >= r && s >= p) ch = 'S';
    else ch = 'P';

    for(int i = 0; i < str.length(); i++){
        cout << help(ch);
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

    int t; cin >> t;
    while(t--){
        solve();
    }

}