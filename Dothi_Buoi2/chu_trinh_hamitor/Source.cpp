
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
vector <int> A[10001];
int N, M;
bool visited[10001];
int X[10001];
void input()
{
	cin >> N >> M;
	for (int i = 1; i <=M; i++)
	{
		int u, v;
		cin >> u >> v;
		A[u].push_back(v);
		A[v].push_back(u);
	}
}
void init()
{
	for (int v = 1; v <=N ; v++)
	{
		visited[v] = false;
	}
}
void solution()
{
	for (int i = 1; i <= N; i++)
	{
		cout << X[i] << " ";

	}
	cout << endl;
}
bool checkAdj(int u, int v)
{
	for (int i = 0; i < A[u].size(); i++)
	{
		if (A[u][i] == v) return true;
	}
	return false;
}
void TRY(int k)
{
	for (int i = 0; i < A[X[k-1]].size(); i++)
	{
		int v = A[X[k - 1]][i];
		if (!visited[v])
		{
			X[k] = v;
			visited[v] = true;
			if (k == N)
			{
				if (checkAdj(X[N], X[1]))
					solution();
			}
			else
			{
				TRY(k + 1);
			}
			visited[v] = false;
		}
		

	}
}
void solve()
{
	input();
	init();
	X[1] = 1;
	visited[1] = true;
	
	TRY(2);
}
int main()
{
	freopen("input.txt", "r", stdin);
	solve();
	return 0;
}