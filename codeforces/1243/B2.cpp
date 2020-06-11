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

    vector< pair<ll, ll> > v;

    for(int i = 0; i < n; i++){
        if(s[i] != t[i]){

            bool check = false;

            for(int j = i+1; j < n; j++){
                if(s[j] != t[j]) {
                    if(s[i] == s[j]){
                        v.pb({j+1, i+1});
                        swap(s[j], t[i]);
                        check = true;
                        break;
                    }else if(s[i] == t[j]){
                        v.pb({j+1, j+1});
                        swap(s[j], t[j]);
                        v.pb({j+1, i+1});
                        swap(s[j], t[i]);
                        check = true;
                        break;
                    }
                }
            }

            if(!check) {
                cout << "No\n";
                return;
            }
        }
    }

    if(v.size() > 2*n){
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    cout << v.size() << '\n';
    for(auto i : v){
        cout << i.first << ' ' << i.second << '\n';
    }
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