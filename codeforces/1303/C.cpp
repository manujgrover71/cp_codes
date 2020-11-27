#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

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

set<int> st[26];

string ans;
vll vis;

bool no = false;

void dfs(ll curr, ll par) {
    vis[curr] = true;
    ans += char(curr + 'a');
    
    for(auto child : st[curr]) {
        if(!vis[child]) {
            dfs(child, curr);
        }else if(child != par) {
            no = true;
            return;
        }
    }
}

// Check for number of Cases!!
void solve() {
    
    for(int i = 0; i < 26; i++) {
        st[i].clear();
    }
    ans = "";
    
    string str; cin >> str;
    
    int n = str.length();
    
    if(n == 1) {
        cout << "YES\n";
        for(char a = 'a'; a <= 'z'; a++) {
            cout << a;
        }cout << '\n';
        return;
    }
    
    vll in(26, 0);
    
    for(int i = 0; i < n-1; i++) {
        auto insert = st[str[i] - 'a'].insert(str[i+1] - 'a');
        st[str[i+1] - 'a'].insert(str[i] - 'a');
        
        if(insert.second) {
            in[str[i] - 'a']++;
            in[str[i+1] - 'a']++;
        }
    }
    
    ll start = -1;
    
    for(int i = 0; i < 26; i++) {
        if(in[i] == 1) {
            start = i;
        }
        if(in[i] > 2) {
            cout << "NO\n";
            return;
        }
    }
    
    if(start == -1) {
        cout << "NO\n";
        return;
    }
    
    vis = vll(26, false);
    
    dfs(start, -1);
    
    if(no) {
        cout << "NO\n";
        return;
    }
    
    for(int i = 0; i < 26; i++) {
        if(!vis[i]) {
            ans += (i + 'a');
        }
    }
    cout << "YES\n";
    cout << ans << '\n';
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
    cin >> t;
    while(t--) {
      solve();
    }
}