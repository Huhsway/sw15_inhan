#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;
int dp[100];
int* arr = NULL;
int main(void) //�� ���� ����� ��ŭ ���ȴ� �ݾҴ� �ݺ�. ����� Ȧ���� ��������
{
	int n = 0, t = 0, count = 0, j = 0;
	scanf_s("%d", &t);
	arr = new int[t];
	memset(arr, 0, sizeof(int)*t);
	for (int i = 0; i < t; i++)
	{
		scanf_s("%d", &n);
		for (j = n; j> 0 ; j--)
		{
			if (dp[j-1] > 0) break; //dp���� �ε��� ��°�� ��� ������ ����
			for (int k = 1; k <= sqrt(j); k++) //��� ���� ���
			{
				if (j % k == 0)
					count += 2;
			}
			if (pow((int)sqrt(j),2) == j)
				count--;
			dp[j-1] = count % 2;
			count = 0;
		}
		for (; j < n; j++)
			dp[j] += dp[j - 1];
		arr[i] = dp[n-1];

	}
	for (int i = 0; i < t; i++)
		printf("%d\n", arr[i]);
	scanf_s("%d", &n);
	return 0;
}