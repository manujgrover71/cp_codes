#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <set>
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
    int arr[n];

    set<int> s;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }

    if(s.size() > 3){
        cout << "NO";
    }else {
        if(s.size() == 2){
            cout << "YES";
        }else if(s.size() == 3){
            ll mx = -1, mn = 1e9, count = 0, ex;
            for(auto i : s){
                count++;
                if(count == 1) mn = i;
                if(count == 2) ex = i;
                else mx = i;
            }
            if((double)(mn + mx) / 2.00 == ex) cout << "YES";
            else cout << "NO";
        }else cout << "YES";
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