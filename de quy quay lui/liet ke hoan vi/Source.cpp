#include <iostream>
using namespace std;
#define nMAX 100;
int n;
int x[100];
int appear[100];//ktra v xuat hien hay chua
int check(int v, int k)
{
	return !appear[v];
}
void solution()
{
	for (int i = 1; i <= n; i++)
	{
		cout << x[i] << "";
	}
	cout << endl;
}
void TRY (int k)
{
	for (int v = 1; v <=n; v++)
	{
		if (check(v, k))
		{
			x[k] = v;
			appear[v] = 1;
			if (k == n)
			{
				solution();
			}
			else
			{
				TRY(k + 1);
			}
			appear[v] = 0;
		}
	}
}
void input()
{
	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		appear[i] = 0;
	}

}

int main()
{
	input();
	TRY(1);
	system("pause");
	return 0;
}