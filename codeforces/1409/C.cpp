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
#define rall(x) (x).rbegin(), (x).rend()
#define ll long long
#define mod 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pb push_back

// D R U L
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

const int mx = 1e6 + 5;
const int INF = mod;

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

// Check for number of Cases!!
void solve()
{
    int size, x, y;

    cin >> size >> x >> y;
    ll ref = -1;
    int next, s = x, last = INT_MAX;
    for (int i = 1; i < x + 1; i++)
    {
        for(int j = 0; j < 19; j++) {
            ref++;
        }

        for (int j = 0; j < y - x + 1; j++)
        {

            int st = i, d = j;
            vector<int> v;
            int count = 0;

            while (count < size)
            {
                v.push_back(st);
                st += d;
                count++;
            }

            if (binary_search(v.begin(), v.end(), x) && binary_search(v.begin(), v.end(), y))
            {
                if (v.back() < last)
                {
                    next = j;
                    s = i;
                    last = v.back();
                }
            }
        }
    }

    int count = 0;

    while (count < size)
    {
        cout << s << " ";

        s += next;
        count++;
    }
    cout << "\n";
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("/ATOMCODES/input.txt", "r", stdin);
    freopen("/ATOMCODES/output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}