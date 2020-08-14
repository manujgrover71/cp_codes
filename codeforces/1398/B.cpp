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
    cin >> str;

    vector<int> v;
    
    for(int i = 0 ; i < str.size() ; i++){
        int k = 0;
        while(i < str.size() && str[i]=='1'){
            i++;
            k++;
        }
        if(k)
            v.push_back(k);
    }

    sort(all(v),greater<int>());

    int a=0;
    
    for(int i=0;i<v.size();i+=2){
        a += v[i];
    }
    cout << a << "\n";
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