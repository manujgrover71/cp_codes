#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

bool checkVal(map< int, vector<int> > m){

    for(auto i: m){
        if(i.second.at(0) != -1)
            return true;
    }

    return false;
}

void solve(){
    int n; cin >> n;
    int changes = 0;
    map< int, vector<int> > m;

    for(int i = 1; i <= n; i++){
        int temp; cin >> temp;
        if(m[temp].empty()){
            m[temp].push_back(0);
            m[temp].push_back(0);
            m[temp].at(0) = i;
        }
        else{
            int last_pos = m[temp].at(0);
            if(last_pos == -1) continue;
            m[temp].at(0) = i;
            if(m[temp].at(1) == 0){
                m[temp].at(1) = i - last_pos;
            }else{
                if(i - last_pos != m[temp].at(1)){
                    m[temp].at(0) = -1;
                    changes++;
                }
            }
        }
    }

    if(!checkVal(m)){
        cout << 0 << "\n";
        return;
    }
    else{
        cout << m.size() - changes << "\n";
        for(auto i: m){
            if(i.second.at(0) != -1)
            cout << i.first << " " << i.second.at(1) << "\n";
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