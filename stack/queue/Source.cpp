#include<iostream>
using namespace std;
#define lmax 1100000
#define rmax 1100000
int first, last;
int qx[1100000], qy[110000];
int qz[1001][1001];
int a, b, c;
int x, y, z;
bool pop()
{
	if (first > last)
	{
		return false;
	}
	x = qx[first];
	y = qy[first];
	z = qz[x][y] + 1;
	first++;
	return true;

}
void push(int x,int y)
{
	

	
}
void pop(int x, int y)
{
	l++;
}
int main()
{
	int n;
	std::cin >> n;
	int a, b, c;
	push(0, 0);
	while (l < r)
	{
		pop(queuey[l], queuey[l]);


	}
	for (int i = 0; i < n; i++)
	{
		std::cin >> a >> b >> c;

	}
	return 0;
}