#include <iostream>
using namespace std;

// �������� ��(<=1000)
int n;
// ������ ��(<=10000)
int m;

// ���� ������
int a;
// ���� ������
int b;
// ����� �ð��� ����
int k;
// ���ٸ� �湮 ������ ��
int g;
// ���ٸ� �湮 ������
int inter[1005];
// �̵� �ð�
int time[1005][1005];

int main(void)
{
	/* �Է� */
	cin >> n >> m;
	cin >> a >> b >> k >> g;

	for (int i = 0; i < g; i++)
	{
		cin >> inter[i];
	}

	int r1, r2, t;
	for (int i = 0; i < m; i++)
	{
		cin >> r1 >> r2 >> t;
		time[r1][r2] = time[r2][r1] = t;
	}






	/* ����� ��� */

	return 0;
}