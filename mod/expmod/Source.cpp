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
int nhanmod(int a, int b, int p)//a*b%p
{
	int c, tam;
	if (a>b)
	{
		tam = a;
		a = b;
		b = tam;

	}
	if (a / 2 == 1)
		c = b %p;
	else
	{
		c = nhanmod(b, a / 2, p);
	}
		
		if (a % 2 == 0)
		{
			
			return addmod(c, c, p);
		}
		else
		{
			return (addmod(addmod(c, c, p),b,p));
		}
			
	
	
}
int expmod(int a, int b, int p)
{
	int c;
	if (b / 2 == 1)
		c = a%p;
	else
	   c = expmod(a, b / 2, p);
	if (b % 2 == 0)
	{
		
		return(nhanmod(c, c, p));
	}
	else
		return(nhanmod(nhanmod(c, c, p), a, p));

}
int main()
{
	int a, b;
	std::cin >> a >> b;
	std::cout << expmod(a, b, 1000000007) << std::endl;
	system("pause");
	return 0;
}