#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int n, m;
int x[100000];
int y[100000];
int s[10000][10000];
void input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> y[i];
	}
}
void solve()
{
	int tam = 0;
	for (int i = 0; i < m; i++)
	{
		if (tam==0 && x[0] == y[i])
			tam = 1;
		 if(tam==1) s[0][i]=1;
		 else s[0][i] = 0;
	}
	 tam = 0;
	for (int i = 0; i < n; i++)
	{
		if (tam == 0 && y[0] == x[i])
			tam = 1;
		if (tam == 1) s[i][0] = 1;
		else s[i][0] = 0;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (x[i] == y[j])
			{
				s[i][j] = s[i - 1][j - 1]+1;
			}
			else
			{
				s[i][j] = (s[i - 1][j]>s[i][j - 1]) ? s[i - 1][j] : s[i][j - 1];
			}
		}
	}
	int kq = s[n - 1][m - 1];
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		//cout << s[i][j] << " ";
	//		if (kq < s[i][j]) kq = s[i][j];
	//	}
	//}
	cout << kq;
}
int main()
{
	freopen("input.txt", "r", stdin);
	input();
	solve();
	return 0;
}