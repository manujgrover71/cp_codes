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
    ll count = 0;
    map<char, ll> m;
    for(int i = 0; i < s.length(); i++){
        m[s[i]]++;
    }
    for(auto i : m){
        if(i.second & 1)
            count++;
    }

    // cout << count << ' ';

    // cout << s.length() - count;

    if(count == 0 || count == 1) {
        cout << "First";
        return 0;
    }

    if(count & 1){
        cout << "First";
    }else{
        cout << "Second";
    }

}