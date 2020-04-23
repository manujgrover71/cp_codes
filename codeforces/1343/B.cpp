#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define ll long long

// ll sum1 = 0;
// int count = 0;
// int x = 0;

int printeven(int n){
    int temp = 0, sum = 0, count = 0;
    while(count != n){
        temp += 2;
        cout << temp << ' ';
        sum += temp;
        count++;
    }
    return sum;
}

void printodd(int n, int k){
    if ((k * k) <= n &&  
        (n + k) % 2 == 0){ 
        int val = 1; 
        int sum = 0; 
        for(int i = 1; i < k; i++){ 
            cout << val << " "; 
            sum += val; 
            val += 2; 
        } 
        cout << n - sum << endl; 
    } 
    else
        cout << "NO \n"; 
}

void solve(){
    int n; cin >> n;
    if(n % 4 != 0){
        cout << "NO\n";
    }else{
        cout << "YES\n";
        int x = printeven(n/2);
        printodd(x, n/2);
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
    while(t--) solve();
}