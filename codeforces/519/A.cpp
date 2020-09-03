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

ll helper(char ch) {
    ch = tolower(ch);

    switch(ch) {

        case 'q': return 9;
        case 'r': return 5;
        case 'b': return 3;
        case 'n': return 3;
        case 'p': return 1;
        case 'k': return 0;
    }

    return 0;
}

// Check for number of Cases!!
void solve() {
    int n = 8;
    string arr[8];

    ll black = 0, white = 0;

    for(int i = 0; i < 8; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < arr[i].length(); j++) {
            if(arr[i][j] != '.') {

                if(arr[i][j] >= 'a' && arr[i][j] <= 'z') {
                    black += helper(arr[i][j]);
                }else white += helper(arr[i][j]);
            }
        }
    }

    if(black > white) {
        cout << "Black";
    }else if(black < white) {
        cout << "White";
    }else cout << "Draw";


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