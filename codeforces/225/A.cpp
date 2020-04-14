#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define ll long long


int main(){
    int n, k, ans = 1;
    cin >> n;
    cin >> k;
    for(int i = 0; i < n; i++){
      int temp1, temp2;
      cin >> temp1 >> temp2;
      if(temp1 == k || temp2 == k || temp1 == 7-k || temp2 == 7-k)
        ans = 0;
    }
    if(ans) cout << "YES";
    else cout << "NO";
}
