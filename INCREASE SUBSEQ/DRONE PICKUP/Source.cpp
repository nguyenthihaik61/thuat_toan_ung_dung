#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int c[100], a[100], n, k;
int f[100][100];
void input()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	for (int i = 1; i <=n; i++)
	{
		cin >> a[i];
	}
	
}
void solve()
{
	
	for (int i = 0; i <=n; i++)
	{
		for (int j = 0; j <=k; j++)
		{
			f[i][j] = -1;
			
		}
	}
	
	f[1][0] = c[1];
	for (int i = 2; i <=n; i++)
	{
		for (int j = 1; j <=k ; j++)
		{
			for (int t = i-50; t < i; t++)
			{
				//cout << "j=" << j << " ";
				if (t >= 1 && f[t][j - 1] >= 0 && t + a[t] >= i)
				{
					f[i][j] = (f[i][j]>f[t][j - 1] + c[i]) ? f[i][j] : (f[t][j - 1] + c[i]);
					cout << "t="<<t<<"a[t]="<<a[t]<<"f[t][j-1]="<<f[t][j-1]<<", c[i]="<<c[i]<<", n=" << i << ", k=" << j << ", f=" << f[i][j] << endl;

				}

			}
			
		}
	}
	cout << f[n][k];
	
}

int main()
{
	freopen("input.txt", "r", stdin);
	input();
	solve();
	
	return 0;
}