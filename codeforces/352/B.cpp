#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
#define ll long long

void solve(){
    int n; cin >> n;
    int changes = 0;
    map< int, pair<int, int> > m;

    for(int i = 1; i <= n; i++){
        int temp; cin >> temp;
        if(m[temp].first == 0 && m[temp].second == 0){
            m[temp].first = i;
        }
        else{
            int last_pos = m[temp].first;
            if(last_pos == -1) continue;
            m[temp].first = i;
            if(m[temp].second == 0){
                m[temp].second = i - last_pos;
            }else if(i - last_pos != m[temp].second){
                m[temp].first = -1;
                changes++;
            }
        }
    }

    if(changes == m.size()){
        cout << 0 << "\n";
        return;
    }
    else{
        cout << m.size() - changes << "\n";
        for(auto i: m){
            if(i.second.first != -1)
            cout << i.first << " " << i.second.second << "\n";
        }
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