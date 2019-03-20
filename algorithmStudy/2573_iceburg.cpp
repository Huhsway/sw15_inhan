#include<stdio.h>
#include<string.h>
using namespace std;

int** arr = NULL, **melt = NULL;
bool **visit = NULL;
int n = 0, m = 0;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
void func(int i,int j)
{
	visit[i][j] = true;
	for (int t = 0; t < 4; t++)
	{
		if (i + dy[t] < 0 || j + dx[t] < 0 || i + dy[t] == n || j + dx[t] == m)//������
			continue;
		if (visit[i + dy[t]][j + dx[t]] == false) //�湮���� ����̸�
		{
			if (arr[i + dy[t]][j + dx[t]] != 0) //���� ��尡 0�� �ƴϸ�
				func(i + dy[t], j + dx[t]); //��� ����
			else
				melt[i][j]--; //���� ��尡 0�̸� ���� ��尪�� 1����(���߿� �ѹ��� ���ҽ��Ѿ���)
		}
	}
}

int main(void)
{
	int count = 0;
	bool check = false;
	scanf_s("%d %d", &n, &m);
	arr = new int*[n];
	melt = new int*[n];
	visit = new bool*[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
		memset(arr[i], 0, sizeof(int)*m);
		melt[i] = new int[m];
		memset(melt[i], 0, sizeof(int)*m);
		visit[i] = new bool[m];

	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &arr[i][j]);
		}
	}
	while (1)
	{
		check = false;
		for (int i = 0; i < n; i++)
		{
			memset(visit[i], 0, sizeof(bool)*m);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] != 0 && check ==false) //0�� �ƴ� ��带 ã�����鼭 �ش� �⵵�� ���� �˻� ��������
				{
					func(i, j); //��� ����
					check = true;
					count++; 
				}
				if (arr[i][j] !=0 && visit[i][j] == false && check == true) //�湮 ���� 0�� �ƴ� ��带 ã�Ҵµ� �̹� �ش� �⵵�� �˻�������
				{
					printf("%d", count-1); //count���� 1�� ���� ������ �ΰ��� ������ �⵵���� �˻縦 �ϱ� ����
					scanf_s("%d", &n);
					return 0;
				}
			}
		}
		for (int i = 0; i < n; i++) //�ֺ��� 0 ��� ������ŭ ��� �κ�
		{
			for (int j = 0; j < m; j++)
			{
				arr[i][j] += melt[i][j];
				melt[i][j] = 0;
				if (arr[i][j] < 0)
					arr[i][j] = 0;
				printf("%d", arr[i][j]);
			}
			printf("\n");
		}
		if (check == false) //��� ��带 �����ߴµ� �� 0�̸�, �� �ѷ� �������� �⵵ ���� �ѹ��� �� ������ �ݺ��� Ż��
			break;
		
	}
	printf("0");
	scanf_s("%d", &n);
	return 0;
}