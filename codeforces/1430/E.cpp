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

class BIT {

    int *bit;
    int N;

    public:

    void update(int x, int val) {
        int ind = x;
        while(ind <= N) {
            bit[ind] += val;
            ind += ((ind) & (-ind));
        }
    }

    BIT(int arr[], int n) {
        N = n+1;
        bit = new int[n+1];
        for(int i = 1; i < N; i++) bit[i] = 0;
        // for(int i = 1; i < N; i++) update(i, arr[i-1]);
    }

    int getSum(int x) {

        if(x < 0) return 0;

        int ind = x + 1;
        int sum = 0;

        while(ind > 0) {
            sum += bit[ind];
            ind -= ((ind) & (-ind));
        }

        return sum;
    }

    int getValue(int x) {
        return getSum(x) - getSum(x-1);
    }

    void changeElem(int x, int val) {
        update(x+1, val-getValue(x));
    }

};

// Check for number of Cases!!
void solve() {
    ll n; cin >> n;
    string str; cin >> str;

    string ref = str;
    reverse(all(ref));

    vector<ll> indexes[26];

    int index = n-1;

    for(int i = n-1; i >= 0; i--) {
        int el = (str[i] - 'a');
        indexes[el].pb(index);
        index--;
    }

    int arr[n];

    for(int i = 0; i < n; i++) {
        arr[i] = indexes[ref[i] - 'a'].back();
        indexes[ref[i] - 'a'].pop_back();
    }

    BIT fenwick(arr, n);

    ll ans = 0;

    for(int i = n-1; i >= 0; i--) {
        int curr = arr[i];
        ans += fenwick.getSum(curr);

        fenwick.update(curr+1, 1);
    }

    cout << ans << '\n';

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