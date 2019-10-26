#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int n, l1, l2;
int a[100000];
int s[100000];
void input()
{
	cin >> n >> l1 >> l2;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}
void solve()
{
	for (int i = 0; i < n; i++)
	{
		s[i] = a[i];
	}
	//int maxs = -1;
	for (int i = l1; i < n; i++)
	{
		//maxs = -1;
		for (int j = i-l2; j <=i-l1; j++)
		{
			if (j >= 0 && s[i] < s[j] + a[i])
				s[i] = s[j] + a[i];
		}
	
	}
	int kq = -1;
	for (int i = 0; i < n; i++)
	{
		//cout << "i= " << i << "s[i]=" << s[i] << endl;
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