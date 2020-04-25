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

    for(int i = 0; i < n; i++) cin >> arr[i];
    int ans[n] = {0};
    vector<int> v;
    sort(arr, arr + n);
    for(int i = 0, j = n-1; i <= j; i++, j--){
        v.push_back(arr[i]);
        if(i != j)
        v.push_back(arr[j]);
    }

    while(!v.empty()){
        cout << v.back() << " ";
        v.pop_back();
    }
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
    while(t--)
        solve();
}   