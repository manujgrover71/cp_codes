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
    int n;
    
    cin >> n;
    
    vector<int> arr(n), temp(n);
    
    map<int,int> ref;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        
        ref[arr[i]]++;
    }

    temp = arr;

    if(n == 1){
        cout << "YES\n" ;
        return;
    }

    sort(all(temp), greater<int>());

    bool check = true;
    for(int i = 0; i < n; i++){
        if(temp[i] != arr[i] || ref[arr[i]] > 1){
            check = false;
            break ;
        }
    }
    
    if(!check) {  
          cout<<"YES\n";
    }
    else {
        cout<<"NO\n";
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
    cin >> t;
    while(t--) {
      solve();
    }
}