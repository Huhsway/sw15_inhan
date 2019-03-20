//#include<stdio.h>
//#include<queue>
//using namespace std;
//int main(void)
//{
//	priority_queue<int> pq;
//	int n = 0, m = 0, sum = 0;
//	bool isPossible = false;
//	scanf_s("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf_s("%d", &m);
//		pq.push(m);
//		sum += m;
//	}
//	if (sum == n * (n - 1) / 2)
//	{
//		isPossible = true;
//		m = n-1;
//		sum = 0;
//		while(!pq.empty())
//		{
//			if (pq.top() > m)
//			{
//				if (pq.top() <= m + sum)
//					sum -= (pq.top() - m );
//				else
//				{
//					isPossible = false;
//					break;
//				}
//			}
//			if (pq.top() < m)
//				sum += m - pq.top();
//			pq.pop();
//			m--;
//		}
//	}
//	if (isPossible) printf("1");
//	else printf("-1");
//	return 0;
//}

#include <iostream>
#include <algorithm>
using namespace std;
int a[10001];
int m[10001];
int d[10001][10001];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		int v = a[i]; // i��° ���� ����
		for (int k = 1; k <= i; k++) {
			if (d[i][k] == 1) v--; // ���� ��⿡�� ���� ������ŭ ����
		}
		for (int j = i + 1; j <= n; j++) {
			if (v > 0) { // ������ �����ִ� ��� (i��° ���� �̱�)
				d[i][j] = 1;
				v--;
			}
			else { // ������ ���� ��� (��� ���� �̱�)
				d[j][i] = 1;
			}
		}
	}
	// m �迭�� ���� ���� ����
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << d[i][j] << " ";
			m[i] += d[i][j];
		}
		cout << '\n';
	}
	sort(m + 1, m + n + 1);
	bool check = true;
	// ���� ���ĵ� �迭�� ���� ������ �迭�� ������ ��ȿ�� ��⿴�ٰ� �Ǵ�
	for (int i = 1; i <= n; i++) {
		if (a[i] != m[i]) check = false;
	}
	cout << (check ? 1 : -1) << '\n';
	return 0;
}
