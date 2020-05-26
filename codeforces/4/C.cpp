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
    map<string, vector<int> > m;
    while(n--){
        string str; cin >> str;
        m[str].push_back(1);

        if(m[str].size() - 1 == 0){
            cout << "OK" << '\n';
        }else{
            cout << str << m[str].size()-1 << '\n';
        }
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