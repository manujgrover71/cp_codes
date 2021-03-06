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

// ------------------------------------------------

template <typename T> istream &operator>>
(istream &is, vector<T> &vec) 
{   for (auto &v : vec) is >> v; return is; }

template<typename T> 
void dout(string name, T arg) {
    cerr << arg << endl;
}

template<typename T1, typename... T2> 
void dout(string names, T1 arg, T2... args) {
    cerr << arg << " | ";
    dout(names.substr(names.find(',') + 2), args...);
}

#ifndef ONLINE_JUDGE
    #define debug(...) dout(#__VA_ARGS__, __VA_ARGS__)
#else
    #define debug(...) 
#endif

// --------------------------------------------------

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

vector<pair<ll, char>> ans;

void helper(pair<ll, ll> range, vll& arr) {

    ll n = arr.size();
    if(n == 1) return;
    ll Max = -1;
    ll same = 0, x = -1;
    for(int i = range.first; i <= range.second; i++) {
        Max = max(Max, arr[i]);
        if(x == -1) {
            same++;
            x = arr[i];
        }else {
            if(x == arr[i]) same++;
        }
    }

    if(same > 1 && same == (range.second - range.first + 1)) {
        cout << "NO\n";
        exit(0);
    }

    for(int i = range.first; i <= range.second; i++) {
        if(arr[i] == Max && i+1 <= range.second && arr[i] > arr[i+1]) {
            ll index = i;
            while(i + 1 <= range.second) {
                ans.pb({index + 1, 'R'});
                i++;
            }
            i = index;
            while(i-1 >= range.first) {
                ans.pb({i+1, 'L'});
                i--;
            }
            return;
        }
    }
    

    for(int i = range.second; i >= range.first; i--) {
        if(arr[i] == Max && i-1 >= range.first && arr[i] > arr[i-1]) {
            ll index = i;
            while(i-1 >= range.first) {
                ans.pb({i + 1, 'L'});
                i--;
            }
            ll temp = i;
            i = index;
            while(i+1 <= range.second) {
                ans.pb({temp+1, 'R'});
                i++;
            }
            return;
        }
    }
}   

// Check for number of Cases!!
void solve() {
    ll n; cin >> n;
    vll arr(n);
    cin >> arr;

    ll m; cin >> m;
    vll brr(m);
    cin >> brr;

    if(arr == brr) {
        cout << "YES\n";
        return;
    }

    ll curr = 0;
    vector<pair<ll, ll>> ref;

    ll last = n-1;

    for(int i = n-1; i >= 0; i--) {
        curr += arr[i];

        if(brr.empty()) {
            cout << "NO";
            return;
        }
 
        if(curr == brr.back()) {
            ref.pb({i, last});
            last = i-1;
            curr = 0;
            brr.pop_back();
        }
    }

    if(!brr.empty()) {
        cout << "NO\n";
        return;
    }

    for(auto i : ref) {
        helper(i, arr);
    }

    if(ans.size() == 0) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for(auto i : ans) {
        cout << i.first << ' ' << i.second << '\n';
    }

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
    // cin >> t;
    while(t--) {
      solve();
    }
}