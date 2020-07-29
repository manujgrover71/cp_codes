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
    string str;

    cin>>str;

    map<char,int> mp;
    
    int mnX = -1;

    for(auto i : str) {
        mp[i]++;
        mnX = max(mnX, mp[i]);
    }
  
    if(mp.size() == 1){
        cout << "0\n" ;
        return ;
    }

    ll n = str.size(), ans = -1;

    for(char i='0';i<='9';i++){
        for(char j='0';j<='9';j++){
            
            bool check = true;
            
            ll ref = 0;
            
            for(int k = 0; k < str.size(); k++){

                if(check && str[k]==i){
                    check = false;
                }
                else if(check == false && str[k]==j){
                    check = true;
                    ref +=2;
                }
            }
            ans = max(ans , ref);
        }
    }
    
    for(auto i:mp){
        ans=max(ans, (ll)i.second);
    }

    cout << n-ans << "\n";

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