#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

#define ll long long
#define mod 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pb push_back

ll power(int x, unsigned int y){
    ll res = 1;
    while(y > 0){
        if(y & 1) res = res * x;
        y >>= 1;
        x *= x;
    }
    return res;
}

void solve(){
    int n, k;
    cin >> n >> k;

    int max = ceil((double)(n*n)/2.00);

    if(k > max){
        cout << "NO\n";
    }else{
        cout << "YES\n";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(k && (i+j) % 2 == 0){
                    cout << "L";
                    k--;
                }else cout << "S";
            }
            cout << "\n";
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