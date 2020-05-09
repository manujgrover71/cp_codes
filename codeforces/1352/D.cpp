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
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int last = arr[0], a = arr[0], b = 0;
    int x = 1, y = n - 1, turn = 1;
    for(int i = 1; x <= y ; i++){
        int current = 0;
        if(i & 1) {
            // y
            while(current <= last){
                if(x > y) break;
                current += arr[y--];
                // turn++;
            }
            b += current;
            last = current;
        }
        else {
            // x
            // if(last == 0)
            while(current <= last){
                current += arr[x++];
                if(x > y) break;
                // turn++;    
            }
            a += current;
            last = current;
        }
        turn++;
        // if(x > y) break;
    }
    cout << turn << ' ' << a << ' ' << b << '\n';
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