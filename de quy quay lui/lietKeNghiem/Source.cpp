#include <iostream>
using namespace std;
int n,m;
int x[100];
int T;
void solution()
{
	for (int i = 1; i <= n; i++)
	{
		cout << x[i];
	}
	cout << endl;
}
int check(int v, int k)
{
	
	if (k < n) return T + v < m;
	return T + v == m;
}
void TRY(int k)
{
	//cout << "try(k)" << endl;
	for (int v = 1; v <= m-T-(n-k); v++)
	{
		if (check(v, k))
		{
			x[k] = v;
			T += v;
		
			if (k == n)
			{
				solution();
			}
			else
			{
				TRY(k + 1);
			}
			T -= v;
		}
	}
}

int main()
{
	//input;
	cin >> n >> m;
	T = 0;
	TRY(1);
	system("pause");
	return 0;
}