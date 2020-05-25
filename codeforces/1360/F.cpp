#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define ll long long

bool isValid(int m, int n, string arr[], string ans){

    for(int i = 1; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < m; j++){
            if(ans[j] != arr[i][j])
                cnt++;
        }
        if(cnt > 1){
            return false;
        }
    }

    return true;

}

void solve(){
    int n, m;
    cin >> n >> m;

    string arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    string ans = arr[0];

    if(isValid(m, n, arr, ans)){
        cout << ans << '\n';
        return;
    }

    for(int i = 0; i < m; i++){
        for(char j = 'a'; j <= 'z'; j++){
            if(j != ans[i]){
                ans[i] = j;
                if(isValid(m, n, arr, ans)){
                    cout << ans << '\n';
                    return;
                }
            }
        }
        ans[i] = arr[0][i];
    }
    cout << "-1\n"; 
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