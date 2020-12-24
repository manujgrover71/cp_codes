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

template <typename T> istream &operator>>
(istream &is, vector<T> &vec) 
{   for (auto &v : vec) is >> v; return is; }

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

string str;
struct node {
   int pair, open, closed;
   node() {pair = open = closed = 0;}
};

vector<node> tree(4 * mx);

void build_tree(ll si, ll ss, ll se) {
   if(ss == se) {
      tree[si].pair = 0;
      tree[si].open = (str[ss] == '(');
      tree[si].closed = (str[ss] == ')');
      return;
   }
   
   ll mid = (ss + se) / 2;
   build_tree(2*si, ss, mid);
   build_tree(2*si + 1, mid + 1, se);
   
   int x = min(tree[2*si].open, tree[2*si + 1].closed);
   tree[si].pair = tree[2*si].pair + tree[2*si + 1].pair + x;
   tree[si].open = tree[2*si].open + tree[2*si + 1].open - x;
   tree[si].closed = tree[2*si].closed + tree[2*si + 1].closed - x;
}

node query(ll si, ll ss, ll se, ll qs, ll qe) {
   
   if(ss > qe || se < qs) {
      node temp;
      return temp;
   }
   
   if(ss >= qs && se <= qe) {
      return tree[si];
   }
   
   ll mid = (ss + se) / 2;
   
   node left = query(2*si, ss, mid, qs, qe);
   node right = query(2*si + 1, mid + 1, se, qs, qe);
   
   node curr;
   int x = min(left.open, right.closed);
   curr.pair = left.pair + right.pair + x;
   curr.open = left.open + right.open - x;
   curr.closed = left.closed + right.closed - x;
   
   return curr;
}

// Check for number of Cases!!
void solve() {
    str += '0';
    string ref; cin >> ref;
    str += ref;
    
    int n = ref.size();
    
    build_tree(1, 1, n);
    
    int q; cin >> q;
    
    while(q--) {
       int a, b;
       cin >> a >> b;
       
       cout << query(1, 1, n, a, b).pair * 2 << '\n';
    }
    
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
   //  cin >> t;
    while(t--) {
      solve();
    }
}