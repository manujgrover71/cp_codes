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
    int n, k;
    cin >> n >> k;

    string str;
    
    cin >> str;

    string ref = "";

    int i = 0;

    while(i < k) {
        ref += str[i];
        i++;
    }

    for(int i = k; i < n; i++){
        if(ref[i%k]!='?'){

            if(str[i]!='?'){

                if(ref[i%k]!=str[i]){
                    cout << "NO\n";
                    return;
                }

            }

        }
        else{
            ref[i % k] = str[i];
        }
    }

    ll o = 0, z = 0, q = 0;
    for(int i = 0; i < k; i++){
        if(ref[i]=='1')   o++;
        if(ref[i]=='0')   z++;
        if(ref[i] == '?') q++;
    }

    if(o > k/2 || z > k/2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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