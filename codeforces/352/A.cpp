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
    int five = 0, zero = 0;   
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a) five++;    
        else zero++;
    }
    if (zero == 0) cout << "-1";
    else if (five < 9) cout << "0";
    else {
        for (int i = 0; i < five / 9; i++)
            for (int j = 0; j < 9; j++)
                cout << "5"; 
        for (int i = 0; i < zero; i++)
            cout << "0"; 
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