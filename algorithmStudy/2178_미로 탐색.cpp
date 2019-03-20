#include<stdio.h>
#include<queue>
using namespace std;
int n, m, cx,cy, i, dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,-1,1 }, arr[100][100];
queue<int> qx, qy;
int main(void)
{
	scanf_s("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf_s("%1d", &arr[i][j]); //�ѱ��ھ� �Է¹ޱ�
	qx.push(0);
	qy.push(0);
	while (1)
	{
		cx = qx.front(); //cx,cy = ������ǥ
		cy = qy.front();
		qx.pop();
		qy.pop();
		if (cy == (n - 1) && cx == (m - 1)) break;
		for (i = 0; i < 4; i++)
		{
			if (cy + dy[i] >= 0 && cy + dy[i]< n && cx + dx[i] >=0 && cx + dx[i]<m && arr[cy + dy[i]][cx + dx[i]]==1)
			{
				qy.push(cy + dy[i]); //ť�� ������ǥ push
				qx.push(cx + dx[i]);
				arr[cy + dy[i]][cx + dx[i]] = arr[cy][cx] + 1;//�迭�� ���������� �Ÿ� ����
			}
		}
		arr[cy][cx] = 0; //�湮�� �� üũ
		
	}
	printf("%d",arr[cy][cx]);
	return 0;
}
