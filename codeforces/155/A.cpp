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
    int temp; cin >> temp;
    int _max = temp, _min = temp, ans = 0;
    for(int i = 1; i < n; i++){
        cin >> temp;
        if(temp > _max){
            _max = temp;
            ans++;
        }
        if(temp < _min){
            ans++;
            _min = temp;
        }
    }
    cout << ans << '\n';
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