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

void solve() {
    string str; cin >> str;

    ll count = 1;
    vector< pair<char, int> > arr;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == str[i+1]) count++;
        else if(str[i] != str[i+1]) {
            arr.pb({str[i], count});
            count = 1;
        }
    }

    for(int i = 0; i < arr.size(); i++) {
        if(arr[i].second > 2) arr[i].second = 2;

        if(i-1 > -1 && arr[i-1].second == 2) 
            arr[i].second = 1;
    }

    for(auto i : arr){
        for(int j = 0; j < i.second; j++)
            cout << i.first;
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