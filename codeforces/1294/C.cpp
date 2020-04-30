#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define ll long long

void solve(){
    int n; cin >> n;
    set<int> s;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0 && !s.count(i)){
            s.insert(i);
            n /= i;
            break;
        }
    }
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0 && !s.count(i)){
            s.insert(i);
            n /= i;
            break;
        }
    }
    if(s.size() < 2 || s.count(n) || n == 1){
        cout << "NO\n";
    }else{
        cout << "YES\n";
        s.insert(n);
        for(auto i : s) cout << i << ' ';
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

    int t; cin >> t;
    while(t--){
        solve();
    }
}