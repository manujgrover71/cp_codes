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
#define rall(x) (x).rbegin(),(x).rend()
#define ll long long
#define mod 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pb push_back

// D R U L
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

const int mx = 1e6 + 5;
const int INF = mod;

ll power(int x, unsigned int y){
    ll res = 1;
    while(y > 0){
        if(y & 1) res = res * x;
        y >>= 1;
        x *= x;
    }
    return res;
}

// Check for number of Cases!!
void solve() {
    int n; cin >> n;

    ll one = 0;

    ll sum = 0;

    for(int i = 0; i < n; i++) {
        int temp; cin >> temp;
        if(temp == 1) one++;
    }
    
    int zero = n - one;

    if(zero >= n/2) {
        cout << n/2 << '\n';
        for(int i = 0; i < n/2; i++) {
            cout << "0 ";
        }
        cout << '\n';
        return;
    }else {
        if(one & 1)one--;
        cout << one << '\n';


        for(int i = 0; i < one; i++) {
            cout << "1 ";
        }
        cout << '\n';
    }
    
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("/ATOMCODES/input.txt", "r", stdin);
        freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }
}