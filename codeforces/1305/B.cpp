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

void solve(){
    string str; cin >> str;

    vector<vi> arr;
    set<int> st;

    while(true) {
        vi open, close;
        for(int i = 0; i < str.length(); i++) {
            if(str[i] == '(')  open.pb(i);
            else close.pb(i);
        }

        reverse(all(close));
        vi ref;
        for(int i = 0; i < min(open.size(), close.size()); i++) {
            if(open[i] < close[i]) {
                ref.pb(open[i]);
                ref.pb(close[i]);
                st.insert(open[i]);
                st.insert(close[i]);
            }
        }

        if(ref.empty())
            break;

        arr.pb(ref);

        string nStr = "";

        for(int i = 0; i < str.length(); i++) {
            if(!st.count(i)) {
                nStr += str[i];
            }
        }

        str = nStr;
    }

    cout << arr.size() << '\n';

    for(auto i : arr) {
        cout << i.size() << '\n';
        sort(all(i));
        for(auto j : i) {
            cout << j+1 << ' ';
        }
        cout << '\n';
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