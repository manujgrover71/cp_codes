#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define ll long long
#define mod 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pb push_back

ll power(int x, unsigned int y)
{
    ll res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = res * x;
        y >>= 1;
        x *= x;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int a = 0;
    for (char i = 'a'; i <= 't'; i++)
    {
        char v = 'z';
        int min = 1000;
        for (int j = 0; j < n; j++)
        {
            if (s1[j] == i && s1[j] != s2[j])
            {
                if (s1[j] > s2[j])
                    continue;
                if ((s2[j] - s1[j]) < min)
                {
                    min = s2[j] - s1[j];
                    v = s2[j];
                }
            }
        }
        if (v != 'z')
        {
            a++;
            for (int j = 0; j < n; j++)
            {
                if (s1[j] == i && s1[j] != s2[j])
                    s1[j] = v;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
        {
            cout << "-1\n";
            return;
        }
    }
    cout << a << "\n";
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}