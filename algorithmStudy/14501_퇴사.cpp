#include <iostream>
#include <algorithm>
using namespace std;
int n, t[1001], dp[1001]; //dp�� i�Ϻ���~ ����ϵ��� ���� �� �ִ� �ִ� ������ ����
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin >> n;	
	for(int i=0;i<n;i++)
		cin >> t[i] >> dp[i]; //�Ⱓ�� t�� ���� / dp���� �� ��¥�� ��� �������� ����ݾ� ����
	for (int i = n; i >= 0; i--) //�ǵڿ�������
		if (i + t[i] > n) dp[i] = dp[i+1]; // �������� ��糯�� �Ѿ�� �ڿ��� �״�� dp�� ����
		else dp[i] = max(dp[i] + dp[i + t[i]], dp[i + 1]); //�̳�¥�� ����ϸ� ��� ����, ������ �� ������ ��
	cout << dp[0];	
	return 0;
}