#include <stdio.h>

int* arr;
int s = 0, n = 0, num = 0;
void func(int i,int sum) //�� ���Ҹ��� �κ����տ� ����o/x �ΰ��� ��찡 �����Ƿ� ��� i��° ���ҿ��� �ΰ��� ��츦 �����ϸ� �ȴ� 
{
	if (sum + arr[i] == s) //���ݱ��� �տ��� ���� ���� ���ؼ� ���ϴ� ������ �˻�
	{
		num++; //������ 1�߰�
	}
	if (i < n - 1) { //������ ���� ������
		func(i + 1, sum); //���� ���� �������� �ʴ� �κ����� �˻�
		func(i + 1, sum + arr[i]); //������� �����ϴ� �κ����� �˻�
	}
}
int main(void)
{
	scanf_s("%d %d", &n, &s);
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
	func(0, 0);
	printf("%d", num);
	scanf_s("%d",&n);
	return 0;
}

