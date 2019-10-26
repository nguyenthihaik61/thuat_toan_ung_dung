#include<iostream>
using namespace std;
int n;
int x[100];
int check(int v, int k)
{
	if (k == 1) return 1;
	if (v == 1 && x[k - 1] == 1) return 0;
	return 1;
}
void solution()
{
	for (int i = 1; i <=n; i++)
	{
		cout << x[i];
	}
	cout << "\n";
}
void TRY(int k)
{
	for (int v = 0; v <=1; v++)
	{
		if (check(v, k))
		{
			x[k] = v;
			if (k == n)
				solution();
			else TRY(k + 1);
		}
	}
}
void input()
{
	cin >> n;
}
int main()
{
	input();
	TRY(1);
	system("pause");
	return 0;
}