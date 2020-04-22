#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define ll long long


int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector< pair<int, int> > v;
    vector< pair<int, int> >::iterator itr;
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        int temp; cin >> temp;
        v.push_back({temp, i});
    }

    sort(v.begin(), v.end());
    int sum = 0;
    for(itr = v.begin(); itr != v.end(); itr++){
        sum += itr->first;
        if(sum > k) break;
        ans.push_back(itr->second);
    }

    cout << ans.size() << '\n';
    if(ans.size() > 0){
        for(auto i : ans){
            cout << i << ' ';
        }
    }
}