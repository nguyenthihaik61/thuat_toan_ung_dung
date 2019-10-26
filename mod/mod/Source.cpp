#include<iostream>
int addmod(int a, int b,int p)
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
	int a, b;
	std::cin >> a >> b;
	std::cout << addmod(a, b,1000000007) << std::endl;
	system("pause");

}