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
    string str; cin >> str;
    if(str[str.length() - 1] == 'o')
        cout << "FILIPINO\n";
    else if(str[str.length() - 1] == 'u')
        cout << "JAPANESE\n";
    else if(str[str.length() - 1] == 'a')
        cout << "KOREAN\n";
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