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
    ll num;

    cin >> num;

    vector<int> arr(num);

    bool vis[num];
    
    int mx=0;
    
    for(int i = 0; i < num; i++){
        cin >> arr[i];
        vis[i]=0;
    }
    
    ll ans = num * (num - 1) / 2;

    for(int i=31;i>=0;i--){
        ll ref = 1ll<<i;
        ll ones = 0,zeros =0;
        for(int j = 0 ;j < num; j++){
            if(vis[j])   continue;
            if((arr[j] & ref)){
                vis[j]=1;
                ones++;
            }
            else    zeros++;
        }
        ans -= ones * zeros;
    }
    cout<<ans<<"\n";
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }
}