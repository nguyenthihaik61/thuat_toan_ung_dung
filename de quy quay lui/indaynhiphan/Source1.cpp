#include<iostream>
using namespace std;
#define NMAX 100
int n;
int x[NMAX];
int appear[NMAX];
void input()
{
	cin >> n;
	for (int i = 0; i < NMAX; i++)
	{
		appear[i] = 0;//chua xuat hien
	}
}
int check(int v, int k)
{
	if (!appear[k]) return 0;
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
	for (int v = 0; v <=n; v++)
	{
		if (check(v, k))
		{
			x[k] = v;
			appear[v] = 1;
			if (k == n)
				solution();
			else TRY(k + 1);
			appear[k] = 0;
		}
	}

}
void solve()
{
	input();
	TRY(1);
}
int main()
{
	solve();
	system("pause");
}