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
    string s, t;
    cin >> s >> t;

    int currMin1 = s[3] - '0', currMin2 = s[4] - '0';
    int currMin = currMin1 * 10 + currMin2;

    int lastMin1 = t[3] - '0',  lastMin2 = t[4] - '0';
    int lastMin = lastMin1 * 10 + lastMin2;

    int currHour1 = s[0] - '0', currHour2 = s[1]-'0';
    int currHour = currHour1*10 + currHour2;

    int lastHour1 = t[0] - '0', lastHour2 = t[1]-'0';
    int lastHour = lastHour1*10 + lastHour2;

    int leftMin = currMin - lastMin;
    // cout << leftMin << '\n';
    bool carry = false;

    if(leftMin < 0) {
        carry = true;
        leftMin += 60;
    }

    if(carry) currHour--;

    if(currHour < lastHour)
        currHour += 24;

    int left = currHour - lastHour;

    string hour = to_string(left);
    string min = to_string(abs(leftMin));

    if(hour.length() == 1) hour = "0" + hour;
    if(min.length() == 1) min = "0" + min;

    cout << hour << ':' << min << '\n';

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