#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>

using namespace std;

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

string s;

void fillall(){
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '?') s[i] = 'A';
	}
}

bool valid(int freq[]){
	for(int i = 0; i < 26; i++){
		if(freq[i] >= 2) return false;
	}
	return true;
}

void solve(){

    cin >> s;
    int freq[26] = {0};

    ll n = s.length();
	if(n < 26) {
        cout << -1;
        return;
    }

	for(int i = 0; i < 26; i++) 
        freq[s[i]-'A']++;
	
    if(valid(freq))
	{
		int cur = 0;
		while(freq[cur]>0) cur++;

		for(int i = 0; i < 26; i++){
			if(s[i] == '?'){
				s[i] = cur + 'A';
				cur++;
				while(freq[cur]>0) cur++;
			}
		}
		fillall();
		cout << s;
		return;
	}
	for(int i = 26; i < n; i++){

		freq[s[i]-'A']++;
        freq[s[i-26]-'A']--;
        
		if(valid(freq)){

			int cur = 0;
			while(freq[cur]>0) cur++;

			for(int j = i - 25; j <= i; j++){
				if(s[j] == '?'){
					s[j] = cur + 'A';
					cur++;
					while(freq[cur]>0) cur++;
				}
			}
			fillall();
			cout << s;
			return;
		}
	}
	cout << -1;

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