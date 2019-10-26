#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int n, m, t;
int c[31][21];
int x[31];
int cost, cost_best;
int dem[21];//dem so nhiem vu nhan vien i
int cmin;
void input()
{
	cmin = 1000000;
	cin >> n >> m >> t;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> c[i][j];
			if (cmin > c[i][j])
				cmin = c[i][j];
		}
	}
}
void solution()
{
	if (cost<cost_best) cost_best = cost;
}
int check(int k, int v)
{
	if (dem[v] + 1 > t) return 0;
	return 1;
}
void TRY(int k)
{
	for (int v = 1; v <= m; v++)
	{
		if (check(k, v))
		{
			x[k] = v;
			dem[v]++;
			cost += c[v][k];
			if (k == n)
				solution();
			else
			{
				if (cost + ((n - dem[v]) * cmin)<cost_best)
					TRY(k + 1);
			}
			cost -= c[v][k];
			dem[v]--;
		}
	}
}
void solve()
{
	cost = 0;
	cost_best = 1000000;
	input();
	for (int i = 1; i <= m; i++)
	{
		dem[i] = 0;
	}
	TRY(1);
	cout << cost_best << endl;
}
int main()
{
	freopen("input.txt", "r", stdin);
	solve();
	return 0;
}