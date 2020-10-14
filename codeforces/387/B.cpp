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



// Check for number of Cases!!
void solve() {
    ll n, m;
    cin >> n >> m;

    priority_queue<ll> pq;
    map<ll, ll> mp;

    vll req(n), have(m);
    
    for(int i = 0; i < n; i++) {
        cin >> req[i];
        mp[req[i]]++;
    }

    for(int i = 0; i < m; i++) {
        cin >> have[i];
        if(mp[have[i]] > 0) {
            mp[have[i]]--;
            n--;
            continue;
        }
        pq.push(have[i]);
    }

    req.clear();

    for(auto i : mp) {
        for(int j = 0; j < i.second; j++) {
            req.pb(i.first);
        }
    }

    sort(rall(req));

    ll i = 0, j = 0;

    while(!pq.empty() && j < (ll)req.size()) {
        if(req[j++] <= pq.top()) {
            pq.pop();
            i++;
        }
    }

    cout << ((ll)req.size() - i) << '\n';

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