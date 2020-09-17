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
    int n, m;
    cin >> n >> m;

    vector<ll> arr(n);
    cin >> arr;


    vector<ll> count(101, 0);

    ll total_sum = arr[0];
    count[arr[0]]++;
    cout << 0 << ' ';

    for(int i = 1; i < n; i++) {

        ll curr_sum = total_sum + arr[i] - m;
        ll ref = 0;

        if(curr_sum > 0) {
            for(int j = 100; j > 0; j--) {

                ll x = j * count[j];
                if(curr_sum <= x) {
                    ref += ceil(curr_sum * 1.0 / j);
                    break;
                }

                ref += count[j];
                curr_sum -= x;
            }
        }

        count[arr[i]]++;
        total_sum += arr[i];
        cout << ref << ' ';
    }
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