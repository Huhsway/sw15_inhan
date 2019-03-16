#include <stdio.h>
using namespace std;
int main(void)
{
	int n = 0, lbs = 0;
	int* arr = NULL;
	int* dpf = NULL;
	int* dpb = NULL;
	scanf_s("%d", &n);
	arr = new int[n];
	dpb = new int[n];
	dpf = new int[n];
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) //�տ������� LIS ����
	{
		dpf[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && dpf[j] + 1 > dpf[i])
				dpf[i] = dpf[j] + 1; //dpf���� �տ������� i�ڸ����� LIS ũ�� ����
		}
	}
	for (int i = n-1; i >= 0 ; i--) //�ڿ������� LIS ����
	{
		dpb[i] = 1;
		for (int j = n-1; j > i; j--)
		{
			if (arr[j] < arr[i] && dpb[j] + 1 > dpb[i])
				dpb[i] = dpb[j] + 1; //dpb������ �ڿ��� i��°(n-1~ n-1-i) ���� LIS ũ�� ����
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (lbs < dpf[i] + dpb[i])
			lbs = dpf[i] + dpb[i]; //i�ڸ� �������� �յ� LIS ���ؼ� �ִ밪
	}	
	printf("%d", lbs-1); //i��°�� �ι� ���ԵǹǷ� 1 ����
	scanf_s("%d", &n);
	return 0;
}