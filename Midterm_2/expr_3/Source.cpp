#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int n, b;
int a[1000], x[1000];
int res;
int dem, max;
void input()
{
	cin >> n >> b;
	max = 1000000;
	for (int i = 1; i <=n ; i++)
	{
		cin >> a[i];
		if (max > a[i]) max = a[i];
	}
	//cout << max << endl;
}
int check(int k, int v)
{
	if (v == 0) dem = dem - a[k + 1];
	else dem = dem + a[k + 1];
	return 1;
}
void solution()
{
	if (dem==b)
	  res++;
}
void TRY(int k)
{
	for (int v = 0; v <= 1; v++)
	{
		if (check(k,v))
			x[k] = v;
		if (k == n - 1)
			solution();
		else  if (dem + (n - k + 1)*max<b)TRY(k + 1);
		if (v == 0) dem = dem + a[k + 1];
		else dem = dem - a[k + 1];

	}
}
void solve()
{
	input();
	dem = a[1];
	res = 0;
	TRY(1);
	cout << res;
}
int main()
{
	freopen("input.txt", "r", stdin);
	solve();
	return 0;

}