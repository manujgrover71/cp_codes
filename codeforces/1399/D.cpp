#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define all(x) (x).begin(),(x).end()
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

void solve() {
    int n; cin >> n;
    string str; cin >> str;

    int arr[n];

    priority_queue<int> zero, one;

    arr[0] = 1;
    int count = 1;

    if(str[0] == '1') {
        one.push(count++);
    }else zero.push(count++);


    int _max = 0;

    for(int i = 1; i < n; i++) {
        if(str[i] == '1') {
            if(!zero.empty()) {
                arr[i] = zero.top();
                int x = zero.top();
                _max = max(_max, x);       
                zero.pop();
                one.push(x);
            }else {
                arr[i] = count;
                _max = max(_max, count);  
                one.push(count);
                count++;
            }
        }else {

            if(!one.empty()) {
                arr[i] = one.top();
                int x = one.top();
                _max = max(_max, x);  
                one.pop();
                zero.push(x);
            }else {
                arr[i] = count;
                zero.push(count);
                _max = max(_max, count);  
                count++;
            }
        }
    }
    cout << count-1 << '\n';
    for(int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }

    cout << '\n';
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