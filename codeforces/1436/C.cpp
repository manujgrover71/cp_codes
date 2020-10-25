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

unsigned long long power(unsigned long long x, 
						int y, int p) 
{ 
	unsigned long long res = 1; // Initialize result 

	x = x % p; // Update x if it is more than or 
	// equal to p 

	while (y > 0) { 
		// If y is odd, multiply x with result 
		if (y & 1) 
			res = (res * x) % p; 

		// y must be even now 
		y = y >> 1; // y = y/2 
		x = (x * x) % p; 
	} 
	return res; 
} 

// Returns n^(-1) mod p 
unsigned long long modInverse(unsigned long long n, int p) 
{ 
	return power(n, p - 2, p); 
} 

// Returns nCr % p using Fermat's little 
// theorem. 
unsigned long long nCrModPFermat(unsigned long long n, 
								int r, int p) 
{ 
	// Base case 
	if (r == 0) 
		return 1; 

	// Fill factorial array so that we 
	// can find all factorial of r, n 
	// and n-r 
	unsigned long long fac[n + 1]; 
	fac[0] = 1; 
	for (int i = 1; i <= n; i++) 
		fac[i] = (fac[i - 1] * i) % p; 

	return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p; 
} 


ll findFact(ll n) {
    if(n <= 0) return 1;
    ll res = 1;
    for(int i = 1; i <= n; i++) {
        res = (res * i) % mod;
    }
    return res;
}

// Check for number of Cases!!
void solve() {
    ll n, a, b;
    cin >> n >> a >> b;

    vll arr(n);

    for(int i = 1; i <= n; i++) {
        arr[i-1] = i-1;
    }

    int left = 0, right = n;

    ll small = 0, big = 0;

    while(left < right) {
        int mid = (left + right) / 2;
        if(arr[mid] < b) small++;
        else if(arr[mid] > b) big++;
        if(arr[mid] <= b) {
            left = mid + 1;
        }else {
            right = mid;
        }
    }

    ll ans = 1;
    ll bigger = n - a;
    ll smaller = a - 1;
    
    if(bigger < big || smaller < small) {
        cout << "0";
        return;
    }

    debug(bigger, big, smaller, small);

    if(big) {
        for(int i = bigger; i > (bigger - big) && i > 0; i--) {
            ans = (ans * i) % mod;
        }
    }

    if(small) {
        for(int i = smaller; i > (smaller - small) && i > 0; i--) {
            ans = (ans * i) % mod;
        }
    }

    ll total = n-1;
    debug(findFact(total - small - big));
    debug(total - small - big);
    ans = ((ans * findFact(total - small - big)) + mod) % mod;

    cout << ((ans + mod) % mod) << '\n';

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