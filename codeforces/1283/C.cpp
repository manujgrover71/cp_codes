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
        vector<int> toGive, toGet;
        int ref[n + 1] = {0};
        int arr[n + 1];
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
            if(arr[i] == 0) toGive.push_back(i);
            ref[arr[i]] = i;
        }

        for(int i = 1; i <= n; i++){
            if(ref[i] == 0) toGet.push_back(i);
        }
        int size = toGive.size();

        for(int i = size - 1; i > -1; i--){
            if(toGive[i] == toGet[i]){
                swap(toGet[i], toGet[i-1]);
            }else if(i > 0 && toGive[i-1] == toGet[i-1]){
                swap(toGet[i], toGet[i-1]);
            }
                arr[toGive[i]] = toGet[i];
        }

        for(int i = 1; i <= n; i++){
            cout << arr[i] << ' ';
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