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

vector<int> getArr(ll size, ll start, ll dif) {

    vector<int> arr(size);
    arr[0] = start;
    for(int i = 1; i < size; i++) {
        arr[i] = arr[i-1] + dif;
    }

    return arr;

}

// Check for number of Cases!!
void solve() {
    ll size, x, y;
    cin >> size >> x >> y;

    vector<int> ans;

    ll last = INT_MAX;

    for(int i = 1; i <= 50; i++) {
        for(int j = 1; j <= 50; j++) {
            vector<int> arr = getArr(size, j, i);
            bool isX = false, isY = false;

            isX = binary_search(all(arr), x);
            isY = binary_search(all(arr), y);

            if(isX && isY) {
                if(last > arr[size-1]) {
                    last = arr[size-1];
                    ans = arr;
                }
            }
        }
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