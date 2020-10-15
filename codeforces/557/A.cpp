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

void print(ll a, ll b, ll c) {
    cout << a << ' ' << b << ' ' << c;
    exit(0);
}

// Check for number of Cases!!
void solve() {
    ll n; cin >> n;

    ll mx1, mn1, mx2, mn2, mx3, mn3;

    cin >> mn1 >> mx1;
    cin >> mn2 >> mx2;
    cin >> mn3 >> mx3;

    ll first = mn1, second = mn2, third = mn3;

    if(first + second + third == n) {
        print(first, second, third);
    }

    ll total = first + second + third;

    total -= first;

    ll temp = min(mx1, n - total);

    total += temp;
    first = 0;
    first += temp;

    if(total == n) {
        print(first, second, third);
    }

    total -= second;
    second = 0;

    temp = min(mx2, n - total);

    total += temp;
    second += temp;

    if(total == n) {
        print(first, second, third);
    }

    total -= third;

    temp = min(mx3, n - total);

    total += temp;
    third = 0;
    third += temp;

    print(first, second, third);
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