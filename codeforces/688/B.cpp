#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define ll long long


int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s; cin >> s;
    for(int i = 0; i < s.length(); i++){
        cout << s[i];
    }
    for(int i = s.length() - 1; i > -1; i--){
        cout << s[i];
    }
    
}   