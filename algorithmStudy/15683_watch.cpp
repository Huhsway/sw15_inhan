#include <stdio.h>
#include <vector>
using namespace std;
int** arr = NULL;
int n = 0, m = 0, least = 987654321;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
vector<int> v;
void watch(int x, int y, int dir, int deWatch) //���� �������� �����ϴ� �Լ�
{
	while (y >= 0 && x >= 0 && y < n && x < m && arr[y][x] != 6)
	{
		if (arr[y][x] <= 0)
			arr[y][x] -= deWatch; //�����Ҷ��� 1�� ����, ���� ������ ���� ���� �� �ٽ� 1�� ����
		x += dx[dir];
		y += dy[dir];
	}
}
int cal() //�ּ� �簢���� ����ϴ� �Լ�
{
	int ret = 0;
	for (int k = 0; k < n; k++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[k][j] == 0)
				ret++;
		}
	}
	if (least > ret)
		least = ret;
	return ret;
}
void func(int index) //dfs ���
{
	int ret = 0, val = 0;
	int i = v[index];
	val = arr[i / m][i%m];

	for (int t = 0; t < 4; t++) //4���� �� �����غ�
	{
		watch(i%m + dx[t], i / m + dy[t], t, 1); //1�� ī�޶��϶��� �׳� �ѓ��� ����
		if (val == 2) //2���̸� 1��°���� �ݴ��ʵ�
			watch(i%m + dx[(t + 2) % 4], i / m + dy[(t + 2) % 4], (t + 2) % 4, 1);
		if (val > 2) //3~5���� �ѹ��⾿ �� �����ϸ� ��
		{
			for (int cam = 1; cam < val - 1; cam++)
				watch(i%m + dx[(t + cam) % 4], i / m + dy[(t + cam) % 4], (t + cam) % 4, 1);
		}
		if (index < v.size() - 1) //ī�޶� Ž�� �� ������
			func(index + 1);
		else //��� ī�޶� Ž�� �� ������
		{
			cal();
		}
		watch(i%m + dx[t], i / m + dy[t], t, -1); //������ ������ �ϹǷ� ���� �����ߴ� �� �����ִ� �κ�
		if (val == 2)
			watch(i%m + dx[(t + 2) % 4], i / m + dy[(t + 2) % 4], (t + 2) % 4, -1);
		if (val > 2)
		{
			for (int cam = 1; cam < val - 1; cam++)
				watch(i%m + dx[(t + cam) % 4], i / m + dy[(t + cam) % 4], (t + cam) % 4, -1);
		}
	}
}



int main(void)
{
	scanf_s("%d %d", &n, &m);
	arr = new int*[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &arr[i][j]);
			if (arr[i][j] > 0 && arr[i][j] < 6)
				v.push_back(i*m + j); //ī�޶� �ִ� ĭ�� �ε����� ���Ϳ� �־���
		}
	}
	least = cal();
	if (v.size() > 0) func(0);
	printf("%d", least);
	scanf_s("%d", &n);
	return 0;
}