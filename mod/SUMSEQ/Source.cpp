#include<iostream>
int addmod(int a, int b, int p)
{
	a = a%p;
	b = b%p;
	int tmp;
	tmp = p - a;
	if (tmp > b) return a + b;
	else return b - tmp;
}
int main()
{
	int n;
	int *a = new int[];
	std::cin >> n;
	int kq = 0;
	for (int i = 0; i < n; i++)
	{
		std::cin>>a[i];
		kq = addmod(a[i], kq,1000000007);
	}
	std::cout << kq << std::endl;
	system("pause");
	return 0;
}