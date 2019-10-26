#include<iostream>
#define MAX_N 30
#define MAX_M 10
int N, M;
int c[MAX_N];
int A[MAX_N][MAX_N];
int x[MAX_N];
int f_best;
int load[MAX_M];
using namespace std;
void input()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> c[i];
	}
	for (int i = 1; i <=N ; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> A[i][j];
		}
	}
}
int check(int v, int k)
{
	
}
void solution()
{

}
void TRY(int k)
{
	for (int v = 1; v <=N; v++)
	{
		if (check(v, k))
		{
			x[k] = v;
			load[v] += c[k];
			if (k == N) solution();
			else TRY(k + 1);
			load[v] -= c[k];
		}
	}
}
void solve()
{
	for (int i = 0; i <=M; i++)
	{
		load[i] = 0;
	}
	f_best = 1000000;
	TRY(1);
	cout << f_best << endl;
}
int main()
{
	input();
	solve();
	return 0;
}