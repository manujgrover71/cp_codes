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
    int arr[3] = {0};
    for(int i = 0; i < 3; i++){
        string temp; cin >> temp;
        if(temp[1] == '>'){
            if(temp[0] == 'A') arr[0] += 2;
            else if(temp[0] == 'B') arr[1] += 2;
            else if(temp[0] == 'C') arr[2] += 2;
            
            if(temp[2] == 'A') arr[0] += 1;
            else if(temp[2] == 'B') arr[1] += 1;
            else if(temp[2] == 'C') arr[2] += 1;
        }
        else {
            if(temp[0] == 'A') arr[0] += 1;
            else if(temp[0] == 'B') arr[1] += 1;
            else if(temp[0] == 'C') arr[2] += 1;
            
            if(temp[2] == 'A') arr[0] += 2;
            else if(temp[2] == 'B') arr[1] += 2;
            else if(temp[2] == 'C') arr[2] += 2;
        }
    }

    if(arr[0] == arr[1] || arr[1] == arr[2] || arr[2] == arr[1])
        cout << "Impossible";
    else{
        string ans = "ABC";
        for(int i = 0; i < 3; i++){
            if(arr[i] == 4) ans[2] = (char)('A' + i);
            else if(arr[i] == 3) ans[1] = (char)('A' + i);
            else if(arr[i] == 2) ans[0] = (char)('A' + i);
        }
        cout << ans;
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