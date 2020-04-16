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
    vector<ll> f, s;
    ll fSum = 0, sSum = 0;
    int last = 0;
    for(int i = 0; i < n; i++){
        ll temp; cin >> temp;
        if(temp > 0){
            f.push_back(temp);
            fSum += temp;
            last = 1;
        }else {
            s.push_back(abs(temp));
            sSum += abs(temp);
            last = 2;
        }
    }

    if(fSum != sSum){
        if(fSum > sSum) cout << "first";
        else cout << "second";
        return;
    }else{
        for(int i = 0; i < min(f.size(), s.size()); i++){
            if(f[i] > s[i]){
                cout << "first";
                return;
            }else if(s[i] > f[i]){
                cout << "second";
                return;
            }
        }
    }
    if(last == 1) cout << "first";
    else cout << "second";
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