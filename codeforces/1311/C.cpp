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
    int n, m; cin >> n >> m;

    string str; cin >> str;
    int pre[26] = {0};
    vector<int> v(n);
    for(int i = 0; i < m; i++){
        int temp; cin >> temp;
        v[temp-1]++;
    }

    for(int i = n-1; i > 0; i--) {
        v[i-1] += v[i];
    }

    for(int i = 0; i < n; i++){
        pre[str[i] - 'a'] += v[i];
        pre[str[i] - 'a']++;
    }

    for(int i = 0; i < 26; i++)
        cout << pre[i] << ' ';
    cout << '\n';
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