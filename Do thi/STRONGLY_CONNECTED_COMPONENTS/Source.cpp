#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>
#define MAX_N 1000001
using namespace std;
int N, M;
vector<int> A[MAX_N];
int d[MAX_N];
int f[MAX_N];
int p[MAX_N];
char color[MAX_N];
int t;
void input()
{
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		int u, v;
		cin >> u >> v;
		A[v].push_back(u);
	}
}
void DFS(int u)
{
	t = t + 1;
	d[u] = t;
	color[u] = 'G';
	for (int i = 0; i < A[u].size(); i++)
	{
		int v = A[u][i];
		if (color[v] == 'W')
		{
			p[v] = u;
			DFS(v);
		}
	}
	t++;
	f[u] = t;
	color[u] = 'B';
}
void printGraph()
{
	for (int v = 1; v <= N; v++)
	{
		cout << "A[" << v << "]=";
		for (int i = 0; i < A[v].size(); i++)
		{
			cout << A[v][i] << " ";

		}
		cout << endl;
	}
}
void DFS()
{
	for (int v = 1; v <= N; v++)
	{
		color[v] = 'W';
	}
	t = 0;
	int dem = 0;
	for (int v = 1; v <= N; v++)
	{
		if (color[v] == 'W')
		{
			DFS(v);
			dem++;
		}
	}
	cout << dem;
}
int main()
{
	freopen("input.txt", "r", stdin);
	input();
	//printGraph();
	DFS();
	return 0;
}

