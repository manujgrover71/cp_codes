#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
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

    int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		int ans = INT_MAX;
		int A = -1, B = -1, C = -1;
		for (int cA = 1; cA <= 2 * a; ++cA) {
			for (int cB = cA; cB <= 2 * b; cB += cA) {
				for (int i = 0; i < 2; ++i) {
					int cC = cB * (c / cB) + i * cB;
					int res = abs(cA - a) + abs(cB - b) + abs(cC - c);
					if (ans > res) {
						ans = res;
						A = cA;
						B = cB;
						C = cC;
					}
				}
			}
		}
		cout << ans << "\n" << A << " " << B << " " << C << "\n";
	}
	
	return 0;
}