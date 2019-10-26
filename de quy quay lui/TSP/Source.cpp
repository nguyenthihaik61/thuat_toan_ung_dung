////chep thay viet//80diem
//#include <iostream>
//using namespace std;
//
//#define MAX 100
//
//int n; // so diem 1, 2,... , n
//int c[MAX][MAX]; // luu khoang cach giua cac diem
//
//int x[MAX];
//int appear[MAX]; // appear[v] = 1 co nghia diem v da dc di qua
//int f; // do dai quang duong tich luy trong qua trinh duyet
//int f_best; // do dai hanh trinh ngan nhat tim thay
//int x_best[MAX];// luu hanh trinh ngan nhat
//int cmin; // la phan tu nho nhat cua ma tran khoang cach
//int check(int v, int k) {
//	if (appear[v] == 1) return 0; // 
//	return 1;                     // return !appear[v]; tra ra appear[v] = 0
//}
//
//void solution() {
//	if (f + c[x[n]][0] < f_best) {
//		f_best = f + c[x[n]][0];
//		for (int i = 0; i <= n; i++) x_best[i] = x[i];
//	}
//}
//void TRY(int k) {
//	for (int v = 1; v <= n; v++)   {
//		if (check(v, k)) {
//			x[k] = v;
//			f += c[x[k - 1]][x[k]]; // cap nhat quang duong tich luy
//			appear[v] = 1;
//			if (k == n) solution();
//			else {
//				if (f + cmin *(n - k + 1) < f_best)
//					TRY(k + 1);
//			}
//			appear[v] = 0;
//			f -= c[x[k - 1]][x[k]];
//
//		}
//	}
//}
//
//void solve(){
//	f = 0;
//	f_best = 100000000;
//	for (int i = 1; i <= n; i++) appear[i] = 0;
//	x[0] = 0; // starting point
//	TRY(1);
//	cout << f_best;
//
//}
//
//void printRoute() {
//	for (int i = 0; i <= n; i++) cout << x_best[i];
//}
//void input() {
//cmin=100000000;
//	cin >> n;
//	for (int i = 0; i <= n; i++) {
//		for (int j = 0; j <= n; j++) {
//			cin >> c[i][j];
//			if (i != j && cmin > c[i][j]) cmin = c[i][j];
//		}
//	}
//
//}
//
//
//int main() {
//	input();
//	solve();
//	system("pause");
//	return 0;
//}

//tu viet//ontap
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#define Nmax 100
using namespace std;
int n;
int c_min;
int c[Nmax][Nmax];
int appear[Nmax];
int x[Nmax];
int f, f_best;
void input()
{
	cin >> n;
	for (int i = 0; i <=n; i++)
	{
		for (int  j = 0; j <=n ; j++)
		{
			cin >> c[i][j];
			if (c_min > c[i][j] && i != j)
			{
				c_min = c[i][j];
				
			}
				
		}
	}
}
int check(int k, int v)
{
	return !appear[v];
}
void solution()
{
	if (f_best > f) f_best=f;
}
void TRY(int k)
{
	for (int v = 1; v <=n; v++)
	{
		if (check(k, v))
		{
			x[k] = v;
			appear[v] = 1;
			f += c[x[k - 1]][v];
			if (k == n)
			{
				f += c[x[k]][0];
				solution();
				f -= c[x[k]][0];
			}
			else
			{
				if (f + c_min*(n + 1-k)<f_best)
					TRY(k + 1);
			}
				f -= c[x[k - 1]][v];
			appear[v] = 0;

		}
	}
}
void solve()
{
	f = 0;
	f_best = 1000000;
	c_min = 1000000;
	x[0] = 0;
	input();
	
	for (int i = 0; i < n; i++)
	{
		appear[i] = 0;
	}
	TRY(1);
	cout << f_best << endl;
}
int main()
{
	freopen("input.txt", "r", stdin);
	solve();
	return 0;
}