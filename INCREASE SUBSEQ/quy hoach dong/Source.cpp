#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int n;
int a[1000000];
int s[1000000];
void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}
void solve()
{
	s[0] = 1;
	int kq = s[0];
	int maxs = -1000000;
	for (int i = 1; i < n; i++)
	{
		maxs = -1000000;
		for (int j = 0; j <= i-1; j++)
		{
			if (a[i]>a[j])
			{
				if (maxs < s[j]+1) maxs = s[j]+1;
			}
		}
		maxs = (maxs>1) ? maxs : 1;
		s[i] = maxs;
	}
	for (int i = 1; i < n; i++)
	{
		//cout << s[i] << " ";
		kq = (kq < s[i]) ? s[i] : kq;
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