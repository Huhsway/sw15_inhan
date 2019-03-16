#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, virus,minVirus=99999, arr[8][8], dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1};
vector<int> zx, zy, vx, vy;
int dfs(int x, int y)
{
	int sum = 0;
	arr[y][x] = 2;
	for (int i = 0; i < 4; i++)
		if (y + dy[i] >= 0 && y + dy[i] < n&&x + dx[i] >= 0 && x + dx[i] < m && !arr[y + dy[i]][x + dx[i]])
			sum += dfs(x + dx[i], y + dy[i]);
	return sum+1;
}
int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2) //���̷��� ��ġ ���Ϳ� ����
			{
				vy.push_back(i);
				vx.push_back(j);
			}
			else if (!arr[i][j]) //��ĭ ��ġ ���Ϳ� ����
			{
				zy.push_back(i);
				zx.push_back(j);
			}
		}
	for (int i = 0; i < zy.size() - 2; i++) //3��for������ �� �ϳ��� ���ĭ�� ������
	{
		arr[zy[i]][zx[i]] = 1; 
		for (int j = i + 1; j < zy.size() - 1; j++)
		{
			arr[zy[j]][zx[j]] = 1;
			for (int k = j + 1; k < zy.size(); k++)
			{
				arr[zy[k]][zx[k]] = 1;
				virus = 0;
				for (int t = 0; t < vy.size(); t++)
					virus += dfs(vx[t], vy[t]); //���̷������� dfs�� Ȯ���ؼ� �� ���� ����
				for (int t = 0; t < zy.size(); t++)
					arr[zy[t]][zx[t]] = 0; //�� ���������� ������� ����
				arr[zy[i]][zx[i]] = 1; //ù��°, �ι�° for���� ���� �״�� ������ �α�
				arr[zy[j]][zx[j]] = 1;
				minVirus = min(minVirus, virus); //���������� �ִ밪 ���ϴ°Ŵϱ� ���̷��� ���̴� �ּ�
			}
			arr[zy[j]][zx[j]] = 0;
		}
		arr[zy[i]][zx[i]] = 0;
	}
	cout << zy.size() + vy.size() - 3 -minVirus; //�������� = ��ĭ - �߰��� �� 3ĭ - ���̷��� ����
	return 0;
}