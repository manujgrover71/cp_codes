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
    string str1, str2;
    cin >> str1 >> str2;

    vector<pair<char, ll>> s1, s2;

    char last = str1[0];

    int cnt = 1;

    for(int i = 1; i < str1.length(); i++) {
        if(str1[i] == last) {
            cnt++;
        }else {
            s1.pb({last, cnt});
            last = str1[i];
            cnt = 1;
        }
    }

    if(cnt) s1.pb({last, cnt});

    last = str2[0];
    cnt = 1;

    for(int i = 1; i < str2.length(); i++) {
        if(str2[i] == last) {
            cnt++;
        }else {
            s2.pb({last, cnt});
            last = str2[i];
            cnt = 1;
        }
    }

    if(cnt) s2.pb({last, cnt});

    if(s1.size() != s2.size()) {
        cout << "NO\n";
    }else {
        for(int i = 0; i < s1.size(); i++) {
            char ch1 = s1[i].first;
            char ch2 = s2[i].first;

            if(ch1 != ch2) {
                cout << "NO\n";
                return;
            }

            ll cnt1 = s1[i].second;
            ll cnt2 = s2[i].second;

            if(cnt2 < cnt1) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
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