#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

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
    int n; cin >> n;
    string s, t; cin >> s >> t;

    vector< pair<char, char> > v;

    int freq[26] = {0};

    for(int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']++;
    }

    for(int i = 0; i < 26; i++) {
        if(freq[i] % 2 != 0){
            cout << "No\n";
            return;
        }
    }

    for(int i = 0; i < n; i++){
        if(s[i] != t[i]){
            v.pb({s[i], t[i]});
        }
    }

    if(v.size() == 1 || v.size() > 2){
        cout << "No\n";
        return;
    }

    if(v[0].first != v[1].first && v[0].second != v[1].second){
        cout << "No\n";
        return;
    }

    cout << "Yes\n";

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