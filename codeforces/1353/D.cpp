#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
#define ll long long

void solve(){
    priority_queue< pair< int, pair<int, int> > > q;

    int n; cin >> n;
    // int arr[n];
    // for(int i = 0; i < n; i++) cin >> arr[i];

    q.push({n, {0, n-1}});
    vector<int> v(n, 0);
    int number = 0;
    while(!q.empty()){
        int L = -1 * q.top().second.first;
        int R = q.top().second.second;

        q.pop();
        
        if(L > R) continue;
        number++;
        int mid = (L + R) / 2;
        v[mid] = number;

        q.push({mid - L + 1, { -1 * L, mid - 1}});
        q.push({R - mid + 1, {-1 * (mid + 1), R}});
    }

    for(auto i : v) cout << i << ' ';
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