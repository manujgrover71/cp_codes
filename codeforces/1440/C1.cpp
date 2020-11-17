#include <algorithm>
#include <iostream>
#include <climits>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;

// ------------------------------------------------

template <typename T>
istream &operator>>(istream &is, vector<T> &vec)
{
	for (auto &v : vec)
		is >> v;
	return is;
}

template <typename T>
void dout(string name, T arg)
{
	cerr << arg << endl;
}

template <typename T1, typename... T2>
void dout(string names, T1 arg, T2... args)
{
	cerr << arg << " | ";
	dout(names.substr(names.find(',') + 2), args...);
}

#ifndef ONLINE_JUDGE
#define debug(...) dout(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#endif

// --------------------------------------------------

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ll long long
#define mod 1000000007
#define nod 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pb push_back

// D R U L
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

const int mx = 1e6 + 5;
const int INF = mod;

vector<vector<ll>> arr(105, vll(105));

// int a[105][105];
ll a[100000], segtre[4000000];

ll query(int si, int ss, int se, int qa, int qb)
{
	if (ss > qb || se < qa)
		return INT_MIN;
	if (ss >= qa && se <= qb)
		return segtre[si];
	ll mid = (ss + se) / 2;
	ll left = query(2 * si, ss, mid, qa, qb);
	ll right = query(2 * si + 1, mid + 1, se, qa, qb);

	return max(left, right);
}
void update(int si, int ss, int se, int qi, ll x)
{
	if (ss == se)
	{
		segtre[si] = x;
		return;
	}
	ll mid = (ss + se) / 2;
	if (qi <= mid)
		update(2 * si, ss, mid, qi, x);
	else
		update(2 * si + 1, mid + 1, se, qi, x);
	segtre[si] = max(segtre[2 * si], segtre[2 * si + 1]);
}

void build_tree(int si, int ss, int se)
{
	if (ss == se)
	{
		segtre[si] = a[ss];
		return;
	}
	ll mid = (ss + se) / 2;
	build_tree(2 * si, ss, mid);
	build_tree(2 * si + 1, mid + 1, se);
	segtre[si] = max(segtre[2 * si], segtre[2 * si + 1]);
}

vector<vll> operations;

int n, m;
void utine(vll cc)
{
	for (int i = 0; i < cc.size(); i += 2)
	{
		if (arr[cc[i]][cc[i + 1]] == 1)
			arr[cc[i]][cc[i + 1]] = 0;
		else
			arr[cc[i]][cc[i + 1]] = 1;
	}
}


void bfs(int src, vector<int> arr[], int vis[], int dist[]){
    
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    dist[src] = 0;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int child : arr[curr]){
            if(!vis[child]){
                q.push(child);
                dist[child] = dist[curr] + 1;
                vis[child] = 1;
            }
        }
    }
}


void dadasds()
{
	int ui = n - 2, uv = m - 2;
	vll temp;

	int c = 0;
	for (int i = ui; i < n; i++)
	{
		for (int j = uv; j < m; j++)
		{
			temp.pb(i);
			temp.pb(j);
			if (arr[i][j] == 1)
				c++;
		}
	}
	if (c == 0)
		return;

	vll vet;
	if (c == 4)
	{
		operations.pb({ui, uv, ui + 1, uv, ui, uv + 1});
		utine(operations.back());
		c = 1;
	}
	if (c == 1)
	{
		for (int i = ui; i < n; i++)
		{
			for (int j = uv; j < m; j++)
			{
				if (arr[i][j] == 1)
				{
					vet.pb(i);
					vet.pb(j);
				}
			}
		}
		int ch = 2;
		
		
		
		for (int i = 0; i < temp.size(); i += 2)
		{
			if (temp[i] == vet[0])
				continue;
			ch--;
			vet.pb(temp[i]);
			vet.pb(temp[i + 1]);

			if (ch == 0)
				break;
		}
		utine(vet);
		operations.pb(vet);
		vet.clear();
		c = 2;
	}
	
	
	
	if (c == 2)
	{
		bool ok = 1;
		for (int i = ui; i < n; i++)
		{
			for (int j = uv; j < m; j++)
			{
				if (arr[i][j] == 0)
				{
					vet.pb(i);
					
					
					vet.pb(j);
				}
				if (ok && arr[i][j] == 1)
				{
					vet.pb(i);
					vet.pb(j);
					ok = 0;
				}
			}
		}
		operations.pb(vet);
		utine(operations.back());
		c = 3;
		
		
	}
	vet.clear();
	if (c == 3)
	{
		for (int i = ui; i < n; i++)
		{
			for (int j = uv; j < m; j++)
			{
				if (arr[i][j] == 1)
				{
					
					
					
					vet.pb(i);
					vet.pb(j);
				}
			}
		}
		operations.pb(vet);
		utine(operations.back());
	}
}
void solve()
{
	cin >> n >> m;
	string fkt[n];
	for (int i = 0; i < n; i++)
		cin >> fkt[i];

	for (int i = 0; i < n; i++)
	{


		for (int j = 0; j < m; j++)


		{
			arr[i][j] = fkt[i][j] - '0';
		}
	}




	for (int i = 0; i < n; i++)
	{
		if (i == n - 1)
			break;
		for (int j = 0; j < m; j++)
		{
			if (i == n - 2 && j == m - 2)
				break;
			if (i == n - 2)
			{
				vll v;
				if (arr[i][j] == 1)
				{
					v.pb(i);
					v.pb(j);
				}
				if (arr[i + 1][j] == 1)
				{
					v.pb(i + 1);
					v.pb(j);
				}
				if (v.empty())
					continue;
				if (v.size() == 2)
				{
					v.pb(i + 1);
					v.pb(j + 1);
				}
				if (v.size() == 4)
				{
					v.pb(i);
					v.pb(j + 1);
				}
				
				
				utine(v);
				operations.pb(v);
				
				
				continue;
			}
			if (arr[i][j] == 0)
			
			
				continue;
			if (j == 0)
				operations.pb({i, j, i + 1, j, i, j + 1});
			else
				operations.pb({i, j, i + 1, j, i + 1, j - 1});
			utine(operations.back());
		}
	}
	dadasds();

	ll refCurr = operations.size();

	cout << refCurr << '\n';

	for (int i = 0; i < refCurr; i++)
	{
		for (int j = 0; j < 6; j++)
	
	
		{
			cout << operations[i][j] + 1 << ' ';
		}
		cout << '\n';
	}

	operations.clear();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("/ATOMCODES/input.txt", "r", stdin);
	freopen("/ATOMCODES/output.txt", "w", stdout);
#endif

	int t = 1;

	cin >> t;

	while (t--)
	{
		solve();
	}
}