#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
using namespace std;
int N, M;
#define MAX_N 100001
vector<int> A[MAX_N];
int d[MAX_N];
void input()
{
	cin >> N >> M;
	for (int i = 1; i <=M ; i++)
	{
		int u, v;
		cin >> u >> v;
		A[u].push_back(v);
		A[v].push_back(u);
	}
}
int BFS(int u)
{
	queue<int>Q;
	Q.push(u);
	d[u] = 0;
	while (!Q.empty())
	{
		int v = Q.front();
		Q.pop();
		for (int i = 0; i < A[v].size(); i++)
		{
			int x = A[v][i];
			if (d[x]>-1)
			{
				if (d[v] % 2 == d[x] % 2) return 0;
			}
			else
			{
				d[x] = d[v] + 1;
				Q.push(x);
			}
		}
	}
	return 1;
}
void solve()
{
	freopen("input.txt", "r", stdin);
	int aws = 1;
	input();
	for (int i = 1; i <= MAX_N; i++)
	{
		d[i] = -1;
	}
	for (int i = 1; i <=N ; i++)
	{
		if (d[i] == -1)
		{
			if (BFS(i) == 0)
			{
				aws = 0;
				break;
			}
		}
	}
	cout << aws << endl;
}
int main()
{
	solve();
	return 0;
}