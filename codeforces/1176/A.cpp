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
    ll n; cin >> n;

    ll two = 0, three = 0, five = 0;

    if(n == 1) {
        cout << "0\n";
        return;
    }

    while(n % 5 == 0) {
        n /= 5;
        five++;
    }

    while(n % 3 == 0) {
        three++;
        n /= 3;
    }

    while(n % 2 == 0) {
        n /= 2;
        two++;
    }

    if(n != 1) {
        cout << "-1\n";
    }else {
        two += three + (five * 2);
        cout << five + three + two << '\n';
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