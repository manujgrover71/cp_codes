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

void solve() {
    int n, p;
    cin >> n >> p;
    string str; cin >> str;
    // p++;
    ll count = 0;
    vi ref;
    for(int i = 0; i < n/2; i++){
        if(str[i] != str[n-i-1]){
            ref.pb(i+1);
            int a = str[i] - 'a';
            int b = str[n - i - 1] - 'a';
            if(a > b) swap(b, a);
            count += min(b-a, abs(b-a-26));
            // cout << a << ' ' << b << ' ' << count << '\n';
        }
    }

    // cout << count << '\n';

    if(p > n/2) p = n - p + 1;

    if(!ref.empty()){
        int res1 = INT_MAX, res2 = INT_MAX;

        res1 = abs(ref.back() - p) + abs(ref.back() - ref[0]);
        res2 = abs(p - ref[0]) + abs(ref.back() - ref[0]);

        count += min({res1, res2});
    }else {
        count = 0;
    }

    cout << count;

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