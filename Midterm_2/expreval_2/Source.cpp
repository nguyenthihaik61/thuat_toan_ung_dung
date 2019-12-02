#include<iostream>
using namespace std;

#define K 1000000007


int n;
int a[1000000];
int mh[1000000];
int tg[1000000];
int to[1000000];

int mymod(int a, int b)
{
	if (a >= 0)  return a %  b;
	int c = (-a) % b;
	return b - c;
}


int addmod(int x, int y)
{
	x = mymod(x, K);
	y = mymod(y, K);
	int z = K - x;
	if (y < z) return x + y;
	return y - z;
}
void input()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n - 1; i++) cin >> mh[i];
}
int mulmod(int a, int b)
{
	if (b == 1) return a % K;
	if (b % 2 == 0)
	{
		int c = mulmod(a, b / 2);
		return addmod(c, c);
	}
	else {
		int c = mulmod(a, b / 2);
		c = addmod(c, c);
		return addmod(a, c);
	}
}
void solve()
{
	input();
	int m = 0;
	int  i = 0;
	int k = -1;
	while (i < n)
	{
		int j = i;
		int f = a[j];
		while (j < n - 1)
		{
			if (mh[j] != 2) break;
			f = mulmod(f, a[j + 1]);
			j++;
		}
		k++;
		tg[k] = f;
		to[k] = mh[j];
		i = j + 1;
	}

	int res = tg[0];
	for (i = 0; i < k; i++)
	{
		if (to[i] == 0) {
			res = addmod(res, -tg[i + 1]);
		}
		else {
			res = addmod(res, tg[i + 1]);
		}
	}
	cout << res;
}
int main()
{
	
	solve();
	system("pause");
	return 0;
}