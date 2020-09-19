#include <bits/stdc++.h>

using namespace std;

#define ll long long


void fun() {
    int num;
    cin >> num;

    int arr[num];

    for(int i = 0; i < num; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + num, greater<int> ());

    int x = 0;
    int y = num - 1;

    vector<ll> ref(num);

    for(int i = 0; i < num; i++) {
        if(i & 1) {
            ref[i] = arr[y--];
        }else {
            ref[i] = arr[x++];
        }
    }

    ll x1 = 0;

    for(int i = 1; i < num - 1; i++) {
        if(ref[i] < ref[i-1] && ref[i] < ref[i+1])
            x1++;
    }


    cout << x1 << '\n';
    for(int i = 0; i < num; i++) {
        cout << ref[i] << ' ';
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    while(t--) {
      fun();
    }
}