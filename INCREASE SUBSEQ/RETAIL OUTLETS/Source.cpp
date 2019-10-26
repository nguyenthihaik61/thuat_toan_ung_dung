#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int n, m;
int a[1000];
long long f[1000][1000];
void input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i < 1000; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			f[i][j] = 0;
		}
	}
}
int main()
{
		freopen("input.txt", "r", stdin);
	input();
	//f[i][j] la so cach phan chia j hang hoa cho i chi nhanh
	//
	for (int i = a[1]; i <= m; i++)
	{
		if (i%a[1] == 0) f[1][i] = 1;
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = a[1] + 1; j <= m; j++)
		{
			int tam = 1;
			while (j - tam*a[i] >=0)
			{

				f[i][j] += f[i - 1][j - tam*a[i]];
				tam++;
			}


		}
	}
	//for (int i = 1; i <=n; i++)
	//{
	//	for (int j = 1; j <=m ; j++)
	//	{
	//		cout << "i=" << i << ", j=" << j << ", f=" << f[i][j] << endl;
	//	}
	//}
	cout << f[n][m]%1000000007;
	return 0;
}