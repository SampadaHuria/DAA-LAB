#include <bits/stdc++.h>
using namespace std;

int MatrixChainOrder(int p[], int i, int j)
{
	if (i == j)
		return 0;
	int k;
	int min = INT_MAX;
	int count;
	for (k = i; k < j; k++)
	{
		count = MatrixChainOrder(p, i, k)
				+ MatrixChainOrder(p, k + 1, j)
				+ p[i - 1] * p[k] * p[j];

		if (count < min)
			min = count;
	}
	return min;
}
int main()
{
	int arr[] = { 10, 30, 5, 60};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout<< MatrixChainOrder(arr, 1, n - 1);
}
