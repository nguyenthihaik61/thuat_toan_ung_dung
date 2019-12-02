//chu trinh euler//di qua tat ca cac canh dung 1 lan
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>
#include<stack>
using namespace std;
set <int> A[100001];
int N, M;
void input()
{
	cin >> N >> M;
	int u, v;
	for (int i = 1; i <= M; i++)
	{
		cin >> u >> v;
		A[u].insert(v);
		A[v].insert(u);
	}
}
void solve()
{
	stack<int> S, CE;
	S.push(1);
	while (!S.empty())
	{
		int x = S.top();
		if (!A[x].empty())
		{
			int y = *(A[x].begin());
			S.push(y);
			A[x].erase(y);
			A[y].erase(x);
		}
		else
		{
			S.pop();
			CE.push(x);
		}
	}
	while (!CE.empty())
	{
		int x = CE.top();
		CE.pop();
		cout << x << " ";
	}
	cout << endl;
}
void printGrapth()
{
	for (int v = 1; v <= n; v++)
	{
		cout << "a[" << v << "]=";
		for (set<int>::iterator it = A[v].begin(); it != A[v].end(); ++it)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	input();
	solve();
	return 0;
}