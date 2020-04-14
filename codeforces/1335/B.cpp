#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long

void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    char arr[b];
    for(int i = 0; i < b; i++)
        arr[i] = 'a' + (int)(i%b);
    for(int i = 0; i < n; i++){
        cout << arr[i%b];
    }
    cout << "\n";
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
        solve();
}