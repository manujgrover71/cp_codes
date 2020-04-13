#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long

void solve(){
    int n, m;
    cin >> n >> m;
    int arr[n];
    memset(arr, -1, sizeof(arr));

    for(int i = 0; i < n; i++){
        for(int j = 1; j <= m; j++){
            char ch; cin >> ch;
            if(ch == 'G'){
                if(arr[i] == -1) arr[i] = j;
            }
            else if(ch == 'S'){
                if(arr[i] != -1) arr[i] = j - arr[i];
                else arr[i] = -2;
            }
        }
    }

    sort(arr, arr + n);

    if(arr[0] == -2){
        cout << -1;
        return;
    }else{
        int ans = 1;
        int last = arr[0];
        for(int i = 1; i < n; i++){
            if(arr[i] != last){
                ans++;
                last = arr[i];
            }
        }
        cout << ans;
        return;
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