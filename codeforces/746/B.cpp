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

    int len; cin >> len;
    string str; cin >> str;
    string ans = "";
    if(len & 1){
        for(int i = len - 1; i > 0; i -= 2)
            ans += str[i-1];
        for(int i = 1; i <= len; i += 2)
            ans += str[i-1];
    }else{
        for(int i = len - 1; i > 0; i -= 2)
            ans += str[i-1];
        for(int i = 2; i <= len; i += 2)
            ans += str[i-1];
    }
    cout << ans;
}