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
    map<ll, pair<int, int> > mp;

    for(int i = 1; i <= n; i++){
        int a; cin >> a;
        mp[a].first = i;
    }

    for(int i = 1; i <= n; i++){
        int a; cin >> a;
        mp[a].second = i;
    }

    int freq[n+1] = {0};

    for(int i = 1; i <= n; i++){

        int first = mp[i].first;
        int second = mp[i].second;
        int index;
        if(first < second){
            first += n;
            index = first - second;
        }else if(first == second){
            index = 0;
        }else{
            index = first - second;
        }
        freq[index]++;
    }

    ll ans = 0;

    for(int i = 0; i <= n; i++){
        ans = max(ans, (ll)freq[i]);
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