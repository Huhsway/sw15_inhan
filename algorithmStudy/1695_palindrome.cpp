#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int* arr = NULL;
int** dp = NULL;
int func(int front,int back) {
	if (front >= back) //��� ���� �����ϸ� ��� Ż��
	{
		return 0;
	}
	if (dp[front][back] != -1) //�̹� ���� ���Ǿ ����Ǿ��ִ� ���
		return dp[front][back];
	if (arr[front] != arr[back]) 
	{
		return dp[front][back] = min(func(front + 1, back), func(front, back - 1)) +1; //����԰� ���ÿ� dp�迭�� �����ؼ� �ߺ���� ����
	}
	else
	{
		return dp[front][back] = func(front + 1, back - 1);//���⵵ ����
	}
}
int main(void)
{
	int n = 0;
	scanf_s("%d", &n);
	arr = new int[n];
	dp = new int*[n];
	for (int i = 0; i < n; i++)
	{
		dp[i] = new int[n];
		memset(dp[i], -1, n * sizeof(int));
		scanf_s("%d", &arr[i]);
	}
	printf("%d", func(0, n - 1));
	scanf_s("%d", &n);
	return 0;
}