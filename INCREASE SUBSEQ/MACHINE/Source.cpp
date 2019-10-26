#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int n;
int s[1000001], t[1000001], ls[1000001], lt[1000001];
int main()
{
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i] >> t[i];
		
	}
	/*int smin = 1000002, smax = 0, tmin = 1000002, tmax = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i] >> t[i];
		if (smin > s[i]) smin = s[i];
		if (smax < s[i]) smax = s[i];
		if (tmin > t[i]) tmin = t[i];
		if (tmax < t[i]) tmax = t[i];
	}

	int stmin = 0, stmax = 0;
	if (smin>tmin) stmin = tmin;
	else stmin = smin;
	if (smax > tmax) stmax = smax;
	else stmax = tmax;*/
	int stmin = 2, stmax = 1000000 - 1;
	for (int i = stmin - 1; i <= stmax + 1; i++)
	{
		ls[i] = 0; lt[i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		ls[t[i]] = lt[s[i]] = t[i] - s[i];

	}
	for (int i = stmin; i <= stmax; i++)
	{
		if (ls[i] < ls[i - 1]) ls[i] = ls[i - 1];
	}
	for (int i = stmax; i >= stmin; i--)
	{
		if (lt[i] < lt[i + 1]) lt[i] = lt[i + 1];
	}
	int kq = 0;
	for (int i = stmin; i <= stmax - 1; i++)
	{
		if (ls[i] != 0 && lt[i + 1] != 0 && kq < ls[i] + lt[i + 1]) kq = ls[i] + lt[i + 1];
	}
	cout << kq;
	//cout << stmin << " " << stmax;
	return 0;
}