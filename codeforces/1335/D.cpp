#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long

void solve(){
    int arr[9][9];
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            char a; cin >> a;
            arr[i][j] = a - '0';

            if(i == 0 && j == 6)
                arr[0][6] = arr[0][5];
            else if(i == 1 && j == 1)
                arr[1][1] = arr[1][0];
            else if(i == 2 && j == 5)
                arr[2][5] = arr[2][4];
            else if(i == 3 && j == 8)
                arr[3][8] = arr[3][5];
            else if(i == 4 && j == 2)
                arr[4][2] = arr[4][1];
            else if(i == 5 && j == 4)
                arr[5][4] = arr[5][3];
            else if(i == 6 && j == 7)
                arr[6][7] = arr[6][6];
            else if(i == 7 && j == 1)
                arr[7][0] = arr[7][1];
            else if(i == 8 && j == 3)
                arr[8][3] = arr[8][2];
        }
    }
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++) cout << arr[i][j];
        cout << '\n';
    }
}

int main(){
    
    int t; cin >> t;
    while(t--)
        solve();
}