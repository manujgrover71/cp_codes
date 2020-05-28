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
#define pb(x) push_back(x)

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
    int n, m;
    cin >> n >> m;

    map<string, int> mp;

    while(n--){
        string str; cin >> str;
        mp[str] += 1;
    }
    string start = "", mid = "";
    for(auto i : mp){
        string ref = i.first;
        reverse(ref.begin(), ref.end());
        if(i.first == ref){
            int _min = mp[ref]/2;
            if(_min == 0 && mid == "") mid += ref;
            else {
                for(int j = 0; j < _min; j++){
                    start += ref;
                }
            }
        }
        else if(mp[ref] != 0){
            int _min = min(i.second, mp[ref]);
            for(int k = 0; k < _min; k++){
                start += i.first;
            }
        }
        mp[ref] = 0;
        mp[i.first] = 0;
    }
    if(start.size() || mid.size()){
        cout << 2 * start.size() + mid.size() << '\n';
        cout << start << mid;
        for(int i = start.length() - 1; i > -1; i--)
            cout << start[i];
        cout << '\n';
    }else{
        cout << 0 << '\n';
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