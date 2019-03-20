#include <stdio.h>
using namespace std;

int main(void)
{
	int n = 0, m = 0, start = 0, dst = 0, cost=0;
	int ** arr = NULL;
	scanf_s("%d", &n);
	arr = new int*[n];
	for (int i = 0; i < n; i++) 
	{
		arr[i] = new int[n];
		for (int j = 0; j < n; j++) {
			arr[i][j] = 100001; //���� ���ǿ��� �־����� ���� 100000 �����̹Ƿ� INF������ �ʱ�ȭ
		}
	}
	
	scanf_s("%d", &m);
	for (int i = 0; i < m; i++) 
	{
		scanf_s("%d %d %d", &start, &dst, &cost);
		if (arr[start-1][dst-1] > cost) //������ ��ġ�� ������ ���� �� �ּҰ��� ����
			arr[start-1][dst-1] = cost;
	}
	for (int t = 0; t < n; t++) //�÷��̵�-�ͼ� �˰���. *���İ��� ������ ���� ó���� �;���
	{
		for (int i = 0; i < n; i++) 
		{
				for (int j = 0; j < n; j++)
				{
					if (i!=j && arr[i][t] + arr[t][j] < arr[i][j])
						arr[i][j] = arr[i][t] + arr[t][j];
				}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j]>100000) //�������ǿ��� ������� ���� ���� 0���� ����ؾ� �Ѵٰ� ��
				arr[i][j] = 0;
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	scanf_s("%d", &n);
	return 0;
}