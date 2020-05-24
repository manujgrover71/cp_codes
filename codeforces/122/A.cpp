#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
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

    int arr[] = {4, 44, 444, 7, 777, 77, 47, 74, 474, 477, 744, 447, 774, 747};

    int size = sizeof(arr) / sizeof(int);

    int a; cin >> a;

    for(int i = 0; i < size; i++){
        if(a % arr[i] == 0){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}