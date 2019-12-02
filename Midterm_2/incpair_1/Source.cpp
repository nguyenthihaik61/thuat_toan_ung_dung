#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
int n;
int a[2000];
using namespace std;
int main()
{
	int count = 0;
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (a[i] < a[j]) count++;
		}
	}
	cout << count;
	return 0;
}