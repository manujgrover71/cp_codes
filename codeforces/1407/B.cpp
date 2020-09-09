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
    int n;
    cin >> n;

    vector<ll> arr(n);
    vector<ll> ans;

    int maxCount = -1, maxIndex;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] > maxCount) {
            maxCount = arr[i];
            maxIndex = i;
        }
    }

    ans.pb(maxCount);
    arr[maxIndex] = -1;

    ll gcd = maxCount;

    for(int i = 0; i < n; i++) {
        ll temp = -1;
        ll ref = gcd;
        ll currIndex = -1;
        for(int j = 0; j < n; j++) {
            if(arr[j] != -1) {
                ref = __gcd(gcd, arr[j]);
                if(ref > temp) {
                    temp = ref;
                    currIndex = j;
                }
                ref = gcd;
            }
        }

        if(currIndex != -1) {
            gcd = temp;
            ans.pb(arr[currIndex]);
            arr[currIndex] = -1;
        }else break;
    }

    for(auto i : ans) {
        cout << i << ' ';
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
    
    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }
}