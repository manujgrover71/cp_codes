#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <set>
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

    int m, n;
    cin >> m >> n;
    int arrB[m][n];
    set<int> rows, cols;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> arrB[i][j];
            if(arrB[i][j] == 0) {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }
    int arrA[m][n];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(rows.find(i) != rows.end() || cols.find(j) != cols.end())
                // cout << 0 << ' ';
                arrA[i][j] = 0;
            // else cout << 1 << ' ';
            else arrA[i][j] = 1;
        }
    }
    int refA[m][n];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            refA[i][j] = 0;
            for(int k = 0; k < m; k++){
                if(arrA[k][j] == 1){
                    refA[i][j] = 1;
                    break;
                }
            }
            for(int k = 0; k < m; k++){
                if(arrA[i][k] == 1){
                    refA[i][j] = 1;
                    break;
                }
            }
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(refA[i][j] != arrB[i][j]){
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES" << '\n';
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << arrA[i][j] << ' ';
        }
        cout << '\n';
    }
}