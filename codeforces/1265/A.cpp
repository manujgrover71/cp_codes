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
    string str; cin >> str;
    
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '?') {
            if(i == 0) {
                if(i+1 == str.length()) {
                    str[i] = 'a';
                    continue;
                }
                if(str[i+1] == '?') {
                    str[i] = 'a';
                }else {
                    for(char x = 'a'; x <= 'c'; x++) {
                        if(x != str[i+1]) {
                            str[i] = x;
                            break;
                        }
                    }
                }
            }else if(i == str.length() - 1) {
                for(char x = 'a'; x <= 'c'; x++) {
                    if(x != str[i-1]) {
                        str[i] = x;
                        break;
                    }
                }
            }else {
                for(char x = 'a'; x <= 'c'; x++) {
                    if(x != str[i-1] && x != str[i+1]) {
                        str[i] = x;
                        break;
                    }
                }
            }
        }
    }
    
    bool check = true;
    
    for(int i = 0; i < str.length() - 1; i++) {
        if(str[i] == str[i+1]) {
            check = false;
            break;
        }
    }
    
    if(check) cout << str << '\n';
    else cout << -1 << '\n';
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