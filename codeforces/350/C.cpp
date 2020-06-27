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

ll power(int x, unsigned int y){
    ll res = 1;
    while(y > 0){
        if(y & 1) res = res * x;
        y >>= 1;
        x *= x;
    }
    return res;
}

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    int x1 = abs(a.first);
    int x2 = abs(b.first);
    int y1 = abs(a.second);
    int y2 = abs(b.second);
    if(x1 != x2) {
        return x1 < x2;
    }else {
        return y1 < y2;
    }
}

char rev(char ch) {
    if(ch == 'D') return 'U';
    else if(ch == 'U') return 'D';
    else if(ch == 'L') return 'R';
    return 'L';
}

void solve() {
    int n; cin >> n;
    vector< pair<ll, ll > > points(n);

    ll ansCount = 0;

    for(int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        points[i].first = x;
        points[i].second = y;
        if(!x || !y) {
            ansCount += 4;
        }else ansCount += 6;
    }

    sort(points.begin(), points.end(), cmp);

    // for(auto i : points) {
    //     cout << i.first << ' ' << i.second << '\n';
    // }

    vector<pair<char, ll> > ref;

    cout << ansCount << '\n';
    for(auto i : points) {
        if(i.first > 0) {
            cout << "1 " << i.first << " R\n";
            ref.pb({'R', i.first});
        }else if(i.first < 0) {
            cout << "1 " << -1 * i.first <<  " L\n";
            ref.pb({'L',  -1 * i.first});
        }

        if(i.second > 0) {
            cout << "1 " << i.second << " U\n";
            ref.pb({'U', i.second});
        }else if(i.second < 0) {
            cout << "1 " << -1 * i.second << " D\n";
            ref.pb({'D', -1 * i.second});
        }

        cout << "2\n";

        while(!ref.empty()) {
            auto i = ref.back();
            ref.pop_back();

            cout << "1 " << i.second << " " << rev(i.first) << '\n';
        }
        cout << "3\n";
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

}