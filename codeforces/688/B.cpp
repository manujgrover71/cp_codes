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
    char x[2 * s.length() + 1];
    for(int i = 0; i < s.length(); i++){
        x[i] = x[2 * s.length()-1-i] = s[i];
    }
    x[2*s.length()] = '\0';
    cout << x;
    
}   