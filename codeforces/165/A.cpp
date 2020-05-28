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
    int n; cin >> n;
    vector< pair<int, int> > v;
    int temp = n;
    while(n--){
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }

    ll ans = 0;

    for(int j = 0; j < temp; j++){
        auto x =  v[j];
        bool up = false, down = false, left = false, right = false, check = false;
        for(int i = 0; i < temp; i++){
            if(j != i){
                if(v[i].first > x.first && v[i].second == x.second)
                    right = true;
                else if(v[i].first < x.first && v[i].second == x.second)
                    left = true;
                else if(v[i].first == x.first && v[i].second < x.second)
                    down = true;
                else if(v[i].first == x.first && v[i].second > x.second)
                    up = true;
            }

            if(up && down && left && right) {
                check = true;
                break;
            }
        }
        if(check) ans++;
    }

    cout << ans;   
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