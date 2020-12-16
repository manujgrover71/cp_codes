#include <algorithm>
#include <iostream>
#include <climits>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;

template <typename T> istream &operator>>
(istream &is, vector<T> &vec) 
{   for (auto &v : vec) is >> v; return is; }

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define ll long long
#define mod 1000000007
#define nod 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pb push_back


// D R U L
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

const int mx = 1e6 + 5;
const int INF = mod;

ll power(ll x, ll y){
    ll res = 1;
    while(y > 0){
        if(y & 1) res = (res * x) % nod;
        y >>= 1;
        x = (x * x) % nod;
    }
    return (res % nod);
}


// Check for number of Cases!!
void solve() {
    ll n; cin >> n;
    vll arr(n); cin >> arr;
    
    ll currSum = 0;
    
    ll ans = n, currAns = 0;
    
    for(int i = 0; i < n; i++) {
        currSum += arr[i];
        currAns++;
        
        ll tempAns = currAns;
        
        bool ok = true;
        for(int j = i+1; j < n; ) {
            ll newSum = arr[j++];
            ll newAns = 0;
            while(j < n && newSum < currSum) {
                newSum += arr[j++];
                newAns++;
            }
            if(newSum != currSum) {
                ok = false;
                break;
            }
            tempAns += newAns;
        }
        if(ok) {
            ans = min(ans, tempAns);
        }
    }
    
    cout << (ans-1) << '\n';
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    freopen("/ATOMCODES/err_output.txt", "w", stderr);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }
}