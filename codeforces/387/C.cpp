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

bool checkSmaller(string a, string b) {
    if(a.length() < b.length()) return true;
    if(a.length() > b.length()) return false;
    return a <= b;
}

// Check for number of Cases!!
void solve() {
    string str; cin >> str;

    ll length = str.length();

    string ref = "";
    ll ans = 0;

    bool check = false;

    for(int i = length-1; i >= 0; i--) {
        if(str[i] == '0') {
            ref += '0';
            check = true;
            str.pop_back();
        }
        else if(check) {
            ref += str[i];
            str.pop_back();
            reverse(all(ref));
            
            if(i > ref.size() || checkSmaller(ref, str)) {
                ans++;
            }else {
                ans++;
                break;
            }
            ref.clear();
            check = false;
        }
        else {
            ref += str[i];
            str.pop_back();
            if(i > ref.size() || checkSmaller(ref, str)) {
                ans++;
            }else {
                ans++;
                break;
            }
            ref.clear();
        }
    }
    // ans++;
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