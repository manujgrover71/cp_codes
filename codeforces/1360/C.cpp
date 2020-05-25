#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define ll long long

void solve(){
    int n; cin >> n;
    int arr[n];
    vector<int> odd, even;
    map<int, int> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] & 1) odd.emplace_back(arr[i]);
        else even.emplace_back(arr[i]);
        m[arr[i]] = 1;
    }

    if(odd.size() % 2 == 0 && even.size() % 2 == 0){
        cout << "YES\n";
        return;
    }

    for(auto i : even){
        if(m.count(i-1) || m.count(i+1)){
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
    
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