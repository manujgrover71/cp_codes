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

// Check for number of Cases!!
void solve() {
    int n; cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int c = INT_MAX;

    for(int i = 0; i <= 100; i++) {
        set<int> st;
        for(int j = 0; j < n; j++) {
            st.insert(abs(arr[j] - i));;
        }
        if(st.size() > 2 || (st.size() == 2 && *st.begin() != 0)) {
            continue;
        }else if((st.size() == 1) || st.size() == 2 && *st.begin() == 0) {
            if(st.size() == 1) {
                c = min(c, *st.begin());
            }
            else {
                int ans = 0;
                for(auto i : st) {
                    ans = i;
                }   
                c = min(ans, c);
            }
        }
    }

    if(c == INT_MAX)
    cout << "-1";
    else cout << c << '\n';

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }
}