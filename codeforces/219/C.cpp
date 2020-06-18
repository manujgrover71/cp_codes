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
    int n, k;
    cin >> n >> k;

    string str; cin >> str;
    int count = 0;
    if(k == 2) {
        string s1 = "", s2 = "";
        for(int i = 0; i < n; i++) {
            if(i & 1)
                s1 += 'A', s2 += 'B';
            else s1 += 'B', s2 += 'A';
        }
        int cntS1 = 0, cntS2 = 0;
        for(int i = 0; i < n; i++) {
            if(str[i] != s1[i]) cntS1++;
            if(str[i] != s2[i]) cntS2++;
        }

        if(cntS1 < cntS2) {
            cout << cntS1 << '\n' << s1;
        }else cout << cntS2 << '\n' << s2;

        return;

    }else {

        for(int i = 1; i < n; i++) {
            if(str[i] == str[i-1]) {
                count++;
                if(i + 1 < n)
                    while(str[i] == str[i-1] || str[i] == str[i+1]) {
                        int x = str[i] - 'A';
                        x = (x + 1) % k;
                        str[i] = x + 'A';
                    }
                else 
                    while(str[i] == str[i-1]) {
                        int x = str[i] - 'A';
                        x = (x + 1) % k;
                        str[i] = x + 'A';
                    }
            }
        }

    }
    cout << count << '\n' << str;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(t--){
        solve();
    }

}