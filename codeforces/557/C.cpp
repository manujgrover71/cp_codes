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
{ for (auto &v : vec) is >> v; return is; }

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
    ll n;
    cin >> n;

    vector<pair<ll, ll>> arr(n+1);

    for(int i = 0; i < n; i++) {
        cin >> arr[i].first;
    }

    arr[n].first = -1;

    ll total_sum = 0;

    for(int i = 0; i < n; i++) {
        cin >> arr[i].second;
        total_sum += arr[i].second;
    }

    arr[n].second = 0;

    sort(arr.begin(), arr.end() - 1);
    map<ll, ll> ref;

    ll ans = 1e18;

    for(int i = 0; i < n; i++) {

        ll curr_count = 0, temp = i, curr_sum = 0;

        while(arr[i].first == arr[i+1].first) {
            curr_sum += arr[i].second;
            curr_count++;
            i++;
        }

        curr_sum += arr[i].second;

        ll toRemove = 0;

        for(int j = 200; j > 0 && curr_count; j--) {
            if(ref[j]) {
                toRemove += j * min(curr_count, ref[j]);
                curr_count = max(0ll, curr_count - ref[j]);
            }
        }

        ans = min(ans, total_sum - curr_sum - toRemove);
        // cout << ans << ' ' << total_sum << ' ' << curr_sum << ' ' << toRemove << '\n';
        for(int j = temp; j < i+1; j++) {
            ref[arr[j].second]++;
        }

    }

    cout << ans;
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