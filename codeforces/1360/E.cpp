    #include <iostream>
    #include <string>
    #include <cstring>
    #include <cmath>
    #include <vector>
    #include <map>
    #include <algorithm>
    using namespace std;
    #define ll long long

    void solve(){
        int n; cin >> n;
        string arr[n];

        for(int i = 0; i < n; i++) cin >> arr[i];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n-1; j++){
                if(arr[j][i] == '1'){
                    if(j == n-1 || i == n-1) continue;
                    else {
                        if(i+1 < n){
                            if(arr[j][i+1] == '1'){
                                // good;
                            }else if( j+1 < n && arr[j+1][i] == '1'){
                                // good;
                            }else {
                                cout << "NO\n";
                                return;
                            }
                        }

                    }
                }
            }
        }

        cout << "YES\n";
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