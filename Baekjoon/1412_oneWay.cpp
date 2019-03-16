#include<stdio.h>
#include<string.h>
using namespace std;

int main(void)
{
	int n = 0;
	char ch = 0;
	bool** arr = NULL;
	scanf_s("%d", &n);
	arr = new bool*[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new bool[n];
		memset(arr[i], false, sizeof(bool)*n);
	}
	getchar();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf_s("%c", &ch);
			if (ch == 'Y')
				arr[i][j] = true;
		}
		getchar();
	}
	for (int i = 0; i < n; i++) //����� ������ �����ϰ� �ܹ��� ������ ����Ŭ�� �ִ����� �����ϸ� ��
	{							//����� ������ ���� �ϳ� ���ּ� ����Ŭ�� ��������� �ʰ� �� �� ����
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] && arr[j][i] && i != j)
				arr[i][j] = arr[j][i] = false;
		}
	}
	for (int k = 0; k < n; k++)///�÷��̵�� ��� ��尣�� ������ ����
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				//���� �÷��̵� �˰��򿡼� i==j�� ���� ���������� 
				//�� ���������� ���� ���� ���ƿ��� ����Ŭ�� ã�ƾ� �ϱ� ������ �������� ����
				if (arr[i][k] && arr[k][j])
					arr[i][j] = true;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i][i]) // �ش� ���� �ٽ� ���ƿ��� ��ΰ� ������(����Ŭ)
		{
			printf("NO");
			scanf_s("%d", &n);
			return 0;
		}
	}
	printf("YES");
	scanf_s("%d", &n);
	return 0;
}