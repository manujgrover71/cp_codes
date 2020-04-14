#include <map>
#include <iostream>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;
#define ll long long

void solve(){
    int n; cin >> n;
    bool check = false;
    if(n == 1) {
        cout << 0 << "\n";  
        check = true;
    }

    map<int, int> m;
    int _max = INT_MIN;
    
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        m[temp]++;
        _max = max(_max, m[temp]);
    }
    
    int len = m.size();

    if(!check){
        if(m.size() == 1 || m.size() == n) cout << 1 << "\n";
        else if(m.size() < _max) cout << m.size() << '\n';
        else if(_max - 1  == len) cout << len << "\n";
        else cout << min(_max, len-1) << "\n";
    }

}

int main(){

    int t; cin >> t;
    while(t--)
        solve();
}