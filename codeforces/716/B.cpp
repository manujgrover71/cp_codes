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
    string str;
    cin >> str;

    if(str.length() < 26) {
        cout << "-1";
        return;
    }

    map<char, ll> mp;
    ll count = 0, extras = 0;

    for(int i = 0; i < 26; i++) {
        if(str[i] != '?') {
            mp[str[i]]++;
            if(mp[str[i]] == 1) count++;
        }else {
            extras++;
        }
    }

    if(count + extras == 26) {
        for(int i = 0; i < 26; i++) {
            if(str[i] != '?') cout << str[i];
            else {
                for(char ch = 'A'; ch <= 'Z'; ch++) {
                    if(mp[ch] == 0) {
                        cout << ch;
                        mp[ch] = 1;
                        break;
                    }
                }
            }
        }   

        for(int i = 26; i < str.length(); i++) {
            if(str[i] == '?') {
                cout << 'A';
            }else cout << str[i];
        }
        return;
    }

    debug(str.length());

    for(int i = 26; i < str.length(); i++) {
        debug("i-26", str[i-26], "i", str[i]);
        if(str[i-26] != '?') {
            mp[str[i-26]]--;
            if(mp[str[i-26]] == 0) count--;
        }else extras--;
        
        if(str[i] != '?') {
            mp[str[i]]++;
            if(mp[str[i]] == 1) count++;
        }else {
            extras++;
        }

        if(count + extras == 26) {
            for(int j = i-25; j <= i; j++) {
                if(str[j] == '?') {
                    for(char ch = 'A'; ch <= 'Z'; ch++) {
                        if(mp[ch] == 0) {
                            mp[ch] = 1;
                            str[j] = ch;
                            break;
                        }
                    }
                }
            }

            for(int i = 0; i < str.length(); i++) {
                if(str[i] == '?') {
                    str[i] = 'A';
                }
            }

            cout << str;
            return;
        }
    }

    cout << "-1";
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