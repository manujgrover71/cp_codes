#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

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

void solve(){
    int n; cin >> n;

    if(n == 1){
        ll a, g;
        cin >> a >> g;
        if((a - g) <= 500) cout << "A";
        else if ((g - a) <= 500) cout << "G";
        else cout << "-1";
        return;
    }

    int a[n], g[n];

    for(int i = 0; i < n; i++) cin >> a[i] >> g[i];

    ll start = a[0];
    ll A = a[0], G = 0;
    string ans1 = "A";
    for(int i = 1; i < n; i++){
        int newA = A + a[i];
        int newG = G + g[i];

        if(abs(newA - G) <= 500){
            A += a[i];
            ans1 += 'A';
            continue;
        }
        else if(abs(newG - A) <= 500){
            G += g[i];
            ans1 += 'G';
            continue;
        }

        break;
    }

    if(ans1.size() == n) {
        cout << ans1;
    }else{
        ans1 = "G";
        A = 0, G = g[0];
        for(int i = 1; i < n; i++){
            int newA = A + a[i];
            int newG = G + g[i];

            if(abs(newA - G) <= 500){
                A += a[i];
                ans1 += 'A';
                continue;
            }
            else if(abs(newG - A) <= 500){
                G += g[i];
                ans1 += 'G';
                continue;
            }

            break;
        }

        if(ans1.size() == n){
            cout << ans1;
        }else cout << "-1";
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