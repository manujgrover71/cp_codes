#include <iostream>
#include <string>
#include <climits>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
#define ll long long

void solve(){
    int n; cin >> n;
    int arr[n];
    priority_queue<ll> q;
    cin >> arr[0];
    q.push(arr[0]);
    ll sum = 0;
    for(int i = 1; i < n; i++){
        cin >> arr[i];
        if(arr[i] > 0 && q.top() < 0 || arr[i] < 0 && q.top() > 0){
            sum += q.top();
            q = priority_queue <ll>();
            q.push(arr[i]);
        }else{
            q.push(arr[i]);
        }
    }

    sum += q.top();

    cout << sum << '\n';
    
    
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) solve();
}