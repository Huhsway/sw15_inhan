#include <stdio.h>
#include <algorithm>
using namespace std;

int main(void)
{
	int n = 0, answer = 0;
	int **arr = NULL;
	int **dp = NULL;
	scanf_s("%d", &n);
	arr = new int*[n];
	dp = new int*[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[i + 1]; //�ﰢ������ ���� �Ҵ�
		dp[i] = new int[i + 1];
		for (int j = 0; j <= i; j++)
		{
			scanf_s("%d", &arr[i][j]);
			dp[i][j] = -1;
		}
	}
	dp[0][0] = arr[0][0];
	for (int i = 1; i < n; i++)
	{
		dp[i][0] = arr[i][0] + dp[i - 1][0]; //�� ����,
		dp[i][i] = arr[i][i] + dp[i - 1][i-1]; //�� �������� �� �ʿ� X
		for (int j = 1; j < i; j++)
			dp[i][j] = arr[i][j] + max(dp[i-1][j-1],dp[i - 1][j]); //�������� ���ؼ� ū���� dp�� ����
	}
	for (int i = 0; i < n; i++)
		answer = max(answer, dp[n - 1][i]);
	printf("%d", answer);
	scanf_s("%d", &n);
	return 0;
}