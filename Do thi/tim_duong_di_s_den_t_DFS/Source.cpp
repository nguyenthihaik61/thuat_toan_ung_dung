#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>
#define MAX_N 100001
using namespace std;
int N, M;
int s, t1;
int check;
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
		A[u].push_back(v);
		A[v].push_back(u);
	}
	cin >> s >> t1;
}
void DFS(int u)
{
	t = t + 1;
	d[u] = t;
	check = 0;
	color[u] = 'G';
	for (int i = 0; i < A[u].size(); i++)
	{
		int v = A[u][i];
		if (color[v] == 'W')
		{
			p[v] = u;
			if (v == t1)
			{
				check = 1;
				break;

			}
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
void path(int s, int t)
{
	DFS(s);
	int i = 0;
	int a[MAX_N];
	a[i] = t1;
	if (check == 1)
	{
		while (a[i] != s)
		{
			i++;
			a[i] = p[a[i - 1]];
		}
		for (int j = i; j >= 0; j--)
		{
			cout << a[j];
		}
	}
	else
	{
		cout << "ko co duong di" << endl;
	}
	
}
void DFS()
{
	for (int v = 1; v <= N; v++)
	{
		color[v] = 'W';
	}
	t = 0;

	path(s, t1);
}
int main()
{
	freopen("input.txt", "r", stdin);
	input();
	//printGraph();
	DFS();

	return 0;
}

