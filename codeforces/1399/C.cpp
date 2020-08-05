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

void solve(){
    int n;

    cin>>n;
    
    int arr[n], _max=0;
    
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    for(int add = 1; add <= 150; add++){
        bool vis[n];

        int num=0;
        
        for(int i = 0; i < n; i++) 
            vis[i]=0;

        for(int i = 0; i < n; i++){
            
            if(vis[i])  continue;
            
            int k = add - arr[i];
            
            for(int j = 0; j < n; j++){

                if(i==j)    continue;
                
                if(k == arr[j] && vis[j]==0){
                    num++;
                    vis[i]=1;
                    vis[j]=1;
                    break;
                }
            }
        }
        _max = max(_max, num);
    }
    cout << _max <<"\n";
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
        solve();
    }

}