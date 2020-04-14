#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long


int main(){

    #ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll noOfDays, a, b;
    cin >> noOfDays >> a >> b;

    for(int i = 0; i < noOfDays; i++){
        ll w; cin >> w;
        cout << ((w%b)*(a%b))%b / a<< " ";
    }

}