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
    int n, k;
    cin >> n >> k;
    if(k > n){
        cout << "NO\n";
    }
    else if(k == n){
        cout << "YES\n";
        int count= 0;
        while(count != k){
            cout << 1 << ' ';
            count++;
        }
        cout << '\n';
    }else{

        if(n % 2 == 0){
            if((n / 2) >= k){
                cout << "YES\n";
                int count = 1;
                while(count != k){
                    cout << 2 << ' ';
                    n -= 2;
                    count++;
                }
                cout << n << '\n';
            }
            else if( (n - 1 - k) & 1 ){
                cout << "YES\n";
                for(int i = 1; i < k; i++){
                    cout << 1 << ' ';
                    n -= 1;
                }
                cout << n << '\n';
            }
            else cout << "NO\n";
        }else if( (n&1) && (k&1) ){
            cout << "YES\n";
            int count = 1;
            while(count != k){
                cout << 1 << ' ';
                n -= 1;
                count++;
            }
            cout << n << '\n';
        }else {
            cout << "NO\n";
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

    int t; cin >> t;
    while(t--){
        solve();
    }
}