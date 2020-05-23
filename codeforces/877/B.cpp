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
	string s;   cin>>s;
    int a=0,b=0,c=0;
 
    for(int i=0;i<s.length();i++)
    {
       if(s[i]=='a')
       {
           a++;
           c++;
       }
        if(s[i]=='b')
        {
            b++;
        }
       
        b=max(a,b);
        c=max(b,c);
    }
    
    cout<<c;
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