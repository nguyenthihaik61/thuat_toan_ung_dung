#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int N, T,D;
int a[2000], t[2000];
int f[2000][2000];
void input()
{
	cin >> N >> T >> D;
	for (int i = 1; i <= N; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> t[i];
	}
	for (int i = 1; i < 2000; i++)
	{
		for (int j = 0; j < 2000; j++)
		{
			f[i][j] = 0;
		}
	}
}
void solve()
{
	f[1][t[1]] = a[1];
	int kq = 0;
	for (int i = 1; i <=N; i++)
	{
		f[i][t[i]] = a[i];
	}
	for (int i = 1; i <=T ; i++)
	{
		for (int j = 2; j <=N ; j++)
		{
			cout << "j=" << j << ", N=  "<<N<<" ";
			for (int tam =1; tam < j; tam++)
			{
				if (tam + D >= j && f[j][i] < f[tam][i - t[j]] + a[j] && i-t[j]>0)
					f[j][i] = f[tam][i - t[j]]+a[j];
			}
			if (kq < f[j][i]) kq = f[j][i];
			cout << "a[j]=" << a[j] << ", f" << j << "," << i << "=" << f[j][i] << endl;
		}
		
	}
	cout << kq;
}
int main()
{
	freopen("input.txt", "r", stdin);
	input();
	solve();
	return 0;
}