#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define ll long long

bool sortinrev(pair<int, int> &a, pair<int, int> &b){
    return (a.first > b.first);
}

void solve(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    if((a*n) != (b*m)){
        cout << "NO\n";
        return;
    }else{
        cout << "YES\n";
        vector< pair< int, int> > freq;
        for(int i = 0; i < m; i++) {
            freq.push_back({ b, i });
        }
        char arr[n][m];
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j < m; j++){
                if(freq[j].first && count < a){
                    arr[i][freq[j].second] = '1';
                    freq[j].first -= 1;
                    count++;
                }
                else {
                    arr[i][freq[j].second] = '0';
                }
            }
            sort(freq.begin(), freq.end(), sortinrev);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << arr[i][j];
            }
            cout << '\n';
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

    int t; cin >> t;
    while(t--){
        solve();
    }
}