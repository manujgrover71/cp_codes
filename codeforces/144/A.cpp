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
    int arr[n];
    int max = -1e5, min = 1e5;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] < min) min = arr[i];
        if(arr[i] > max) max = arr[i];
    }

    int ans = 0, got = 0;

    for(int i = 0; i < n; i++){
        if(arr[i] == max){
            ans += i;
            got = i;       
            break;
        }
    }

    for(int i = n-1; i > -1; i--){
        if(arr[i] == min){
            if(i < got){
                ans += n-2-i;
            }else ans += n-1-i;
            break;
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