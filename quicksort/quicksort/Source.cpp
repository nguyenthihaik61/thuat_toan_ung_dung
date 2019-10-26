#include<iostream>
void swap(int &a, int &b)
{
	int tam;
	tam = a;
	a = b;
	b = tam;

}
int partition(int a[], int l, int r, int indexPivot)
{
	int pivot = a[indexPivot];
	swap(a[indexPivot], a[r]);
	int storeIndex = l;
	for (int i = l; i < r; i++)
	{
		if (a[i] < pivot)
		{
			swap(a[storeIndex], a[i]);
			storeIndex++;
		}
	}
	swap(a[storeIndex], a[r]);
	return storeIndex;
}
void quicksort(int a[], int l, int r)
{
	if (l < r)
	{
		int index = (l + r) / 2;
		index = partition(a, l, r, index);
		if (l < index)
			quicksort(a, l, index-1);
		if (index < r)
			quicksort(a, index + 1, r);
	}
}
int main()
{
	int n;
	std::cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> a[i];
	}
	quicksort(a, 0, n-1);
	for (int i = 0; i < n; i++)
	{
		std::cout<< a[i]<<" ";
	}
	system("pause");
	return 0;
}