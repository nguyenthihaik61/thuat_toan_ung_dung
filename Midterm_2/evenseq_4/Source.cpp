#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int n;
int a[1000000], sumchan[1000000], sumle[1000000];
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
	if (a[0] % 2 == 0)
	{
		sumchan[0] = a[0];
		sumle[0] = 0;
	}
	else
	{
		sumle[0] = a[0];
		sumchan[0] = 0;
	}
	for (int i = 1; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			if (sumchan[i - 1]>0) sumchan[i] = sumchan[i - 1]+a[i];
			else sumchan[i] = a[i];
			if(sumle[i-1]!=0) sumle[i] = a[i] + sumle[i - 1];
			else sumle[i] = 0;
		}
		else
		{
			if (sumchan[i - 1] > 0) sumle[i] = a[i] + sumchan[i - 1];
			else sumle[i] = a[i];
			if (sumle[i-1]!=0) sumchan[i] = sumle[i - 1] + a[i];
			else sumchan[i] = 0;
		}
	}
	int kq = 0;
	for (int i = 0; i < n; i++)
	{
		if (kq < sumchan[i]) kq = sumchan[i];
	}
	cout << kq;

}
int main()
{
	freopen("input.txt", "r", stdin);
	for (int i = 0; i < n; i++)
	{
		sumchan[i] = 0;
		sumle[i] = 0;
	}
	input();
	solve();
	return 0;

}