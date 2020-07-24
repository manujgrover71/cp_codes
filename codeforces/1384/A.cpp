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

string change(string str, string last, int len) {

    for(int i = 0; i <= len; i++) {
        str[i] = last[i];
    }

    if(str[len] == 'z') str[len] = 'd';
    else str[len]++;

    return str;
}

void solve() {

    int n;
    cin >> n;
    
    int last = 0;
    string str = "";

    for(int i = 0; i < 200; i++) {
        str += 'a';
    }

    int temp; cin >> temp;

    cout << str << '\n';

    string x = str;

    x = change(x, str, temp);

    cout << x << '\n';

    for(int i = 1; i < n; i++) {
        cin >> temp;
        str = change(str, x, temp);
        x = str;
        cout << str << '\n';
    }

   //  cout << '\n';

    return;

    // for(int i = 0; i < n; i++) {
    //     int temp; cin >> temp;
    //     if(last == 0 && temp == 0) {
    //         cout << char('a' + (i+rand() % 26)) << '\n';
    //         last = temp;
    //         continue;
    //     }
    //     string str = "";
    //     for(int j = 0; j < max(last, temp); j++) {
    //         str += ('a' + (j % 26));
    //     }
    //     last = temp;
    //     cout << str << '\n';
    // }

    // string str = "";
    // if(last == 0) {
    //    cout << char('a' + (n%26)) << '\n';
    //    return;
    // }
    // for(int i = 0; i < last; i++) {
    //     str += ('a' + (i % 26));
    // }

    // cout << str << '\n';
    // cout << '\n'
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    // t = 1;
    while(t--){
        solve();
    }

}