#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define ll long long

void solve(){
    int m, n; cin >> m >> n;
    int arr[m+1];
    for(int i = 1; i <= m; i++)
        cin >> arr[i];
    
    set<int> p;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        p.insert(temp);
    }
    for(int j = 0; j < 100; j++)
    for(int i = 2; i <= m; i++){
        if(arr[i] < arr[i-1]){
            if(!p.count(i-1)){
                cout << "No\n";
                return;
            }else swap(arr[i], arr[i-1]);
        }
    }
    cout << "YES\n";
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