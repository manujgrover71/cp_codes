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

#define all(x) (x).begin(),(x).end()
#define ll long long
#define mod 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pb push_back


ll solve(string str, char c) {

    if(str.length() == 1) {
        return str[0] != c;
    }
    
    int mid = str.size()/2;

    ll cnt1 = solve(string(str.begin(), str.begin() + mid), c+1);

    cnt1 += str.size() / 2 - count(str.begin() + mid, str.end(), c);

    ll cnt2 = solve(string(str.begin() +  mid, str.end()), c+1);

    cnt2 += str.size() / 2 - count(str.begin(), str.begin() + mid, c);

    return min(cnt1, cnt2);
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string str; cin >> str;
        cout << solve(str, 'a') << '\n';
    }

}