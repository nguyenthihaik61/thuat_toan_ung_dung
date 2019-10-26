#include<iostream>
int main()
{
	int n;
	std::cin >> n;
	int *a = new int[n];
	long long int *sum = new long long int[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		sum[i] = 0;
	}
	sum[0] = a[0];
	int min = 0;
	if (min>a[0])
		min = a[0];
	int max = sum[0];
	for (int i = 1; i < n; i++)
	{
		sum[i] = sum[i - 1] + a[i];
		if (min>sum[i])
			min = sum[i];
		if (max < sum[i])
			max = sum[i];
	}
	//std::cout << min << " " << max << std::endl;
	std::cout << max - min << std::endl;
	system("pause");
	return 0;
}