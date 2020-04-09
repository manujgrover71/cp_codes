#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long

int solve(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    ll rem = 0;
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(i) rem += arr[i];
    }

    if(arr[0] == k) return k;
    else{
        if(k > rem){
            return arr[0] + rem <= k ? arr[0] + rem : k;
        }
        else return k;
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--)
        cout << solve() << "\n";
}