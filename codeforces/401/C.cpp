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
    int zero, ones;
    cin >> zero >> ones;

    if(zero < (ceil(double((ones/2.00))) - 1) || (zero > ones && zero - ones > 1)){
        cout << -1;
    }
    else{

        if(zero > ones){
            while(zero || ones){
                if(zero) cout << "0", zero--;
                if(ones) cout << "1", ones--;
            }
        }else{
            while(zero || ones){
                if(zero != ones){
                    if(ones >= 2){
                        cout << "11";
                        ones -= 2;
                    }else if(ones) cout << "1", ones--;

                    if(zero) cout << "0", zero--;
                }else{
                    if(ones) cout << "1", ones--;
                    if(zero) cout << "0", zero--;
                }
            }
        }
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