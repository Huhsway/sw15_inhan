#include<stdio.h>
#include<string.h>
using namespace std;

int main(void)
{
	int n = 0, sum = 0;
	int** arr = NULL;
	bool** deleted = NULL;
	scanf_s("%d", &n);
	arr = new int*[n];
	deleted = new bool*[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
		memset(arr[i], 0, sizeof(int)*n);
		deleted[i] = new bool[n];
		memset(deleted[i], false, sizeof(bool)*n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf_s("%d", &arr[i][j]);
		}
	}
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (k == i || k == j || i == j)
					continue;
				if (arr[i][j] > arr[i][k] + arr[k][j]) //�־��� ���� �ּ� �̵��ð��� �ƴ� ��� -1���
				{
					printf("-1");
					return 0;
				}
				if (arr[i][j] == arr[i][k] + arr[k][j]) //i->j�� k�� �����ؼ� ���� �ð��̹Ƿ� ���� ��
				{
					deleted[i][j] = true;
				}

			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (arr[i][j] > 0 && deleted[i][j] == false) //delete�迭�� ���Ե��� �ʰ� ���� ���� ������ �� �ʿ��� ����
			{
				sum += arr[i][j];
			}
		}
	}
	printf("%d", sum);
	return 0;
}