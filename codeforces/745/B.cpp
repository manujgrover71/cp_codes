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



// Check for number of Cases!!
void solve() {
    ll n, m;
    cin >> n >> m;

    char arr[n][m];

    ll firstX = -1, firstY = -1, secondX = -1, secondY = -1;
    ll count = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];

            if(arr[i][j] == 'X') {
                count++;
                if(firstX == -1) {
                    firstX = i, firstY = j;
                }
                if(secondX == -1) {
                    secondX = i, secondY = j;
                }

                firstX = min(firstX, (ll)i);
                firstY = min(firstY, (ll)j);
                secondX = max(secondX, (ll)i);
                secondY = max(secondY, (ll)j);
            }
        }
    }

    ll currCount = (abs(firstX - secondX) + 1) * (abs(firstY - secondY) + 1);

    if(count == currCount) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
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