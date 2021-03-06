#include <algorithm>
#include <bits/stdc++.h>
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

bool check(vll& arr, double canAnswer, double total) {

    ll n = arr.size() / 2;
    if((canAnswer * n) + (2 * n * canAnswer) > total) return false;
    for(int i = 0; i < n; i++) {
        if(canAnswer > arr[i]) return false;
    }
    for(int i = n; i < 2 * n; i++) {
        if(2 * canAnswer > arr[i]) return false;
    }
    return true;
}

// Check for number of Cases!!
void solve() {
    double n, w;
    cin >> n >> w;

    vll arr((ll)2 * n);
    cin >> arr;

    sort(all(arr));

    ll boy_max = arr[(ll)n];
    ll girl_max = arr[0];

    // double left = 0, right = girl_max;

    // double ans = 0;

    // ll iteration_count = 1e7;
    double eps = -1e6;  

    // for(int i = 0; i < iteration_count && left + eps < right; i++) {
    //     double mid = 0.5f * (left + right);

    //     double total = (mid * n) + (2 * n * mid);
    //     double ref = mid * 2;

    //     if((ref) <= boy_max && total <= w) { 
    //         ans = mid;
    //         left = mid;
    //     }else {
    //         right = mid;
    //     }
    // }

    // double girls = ans * n;
    // double boys = 2 * girls;

    // cout.precision(6);

    // cout << (girls + boys) << '\n';


    double left = 0, right = 1e9;
    double ans = 0;

    for(int i = 0; i < 1000 && left + eps < right; i++) {
        double mid = 0.5f * (left + right);

        if(check(arr, mid, w)) {
            left = mid;
            ans = mid;
        }else right = mid;
    }

    // cout << ans << '\n';

    double girls = ans * n;
    double boys = 2 * girls;

    cout << fixed << setprecision(10) << (girls + boys);
    
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