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
#define rall(x) (x).rbegin(),(x).rend()
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

bool check(string str, string x) {

    for(int i = 0; i < str.length(); i++) {
        bool poss = false;
        for(int j = 0; j < x.length(); j++) {
            if(str[i+j] == x[j]) {
                poss = true;
                break;
            }
        }
        if(!poss) return false;
    }

    return true;

}

// Check for number of Cases!!
void solve() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    if(n == 1) cout << str << '\n';
    else {
        for(int i = 0; i < n; i++) {
            cout << str[n-1];
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
    
    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }
}