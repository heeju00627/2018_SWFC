#include <iostream>
#define width 9
#define height 5
#define num 12
using namespace std;

// ���� ��Ÿ ����
int point[21] = { 4, 4, 0, 1, 1, 1, 1, 1, 0, 2, 3, 2, 0, 1, 1, 1, 1, 1, 0, 4, 4 };
// �Է°�
char line[height][width + 1];

// ���� �� ���� �̷���� �� ��ȣ
int sumpos[6][4] = { {1, 3, 6, 8}, {1, 4, 7, 11}, {2, 3, 4, 5},
					{8, 9, 10, 11}, {2, 6, 9, 12}, {5, 7, 10, 12} };

// ���� ����
int star[num + 1];
// ���� ����
int used[num + 1];
// ä������ ���� �ڸ�
int leftn[num + 1];
// �� �� ���� ��
int leftcnt;

void input();
void output();

void backtracking(int k)
{
	// ��� ���ڸ� �� ä������
	if (k == leftcnt)
	{
		int sum;

		for (int i = 0; i < 6; i++)
		{
			sum = 0;
			// ���پ� sum ���
			for (int j = 0; j < 4; j++)
			{
				int pos = sumpos[i][j];
				sum += star[pos];
			}

			// �߸��� ä������
			if (sum != 26)
			{
				return;
			}
		}

		// ���
		output();
	}

	// ���ڸ� ä��������
	for (int i = 1; i <= num; i++)
	{
		// ������� ���� i��
		if (used[i] == 0)
		{
			used[i] = 1;

			// ���� ä���� ���� cur��° star ĭ��
			int cur = leftn[k + 1];
			star[cur] = i;
			backtracking(k + 1);
			
			used[i] = 0;
		}
	}
}

/* ���� �Է� */
void input(void)
{
	int n;

	cin >> line[0];
	line[0][width] = '\0';
	n = (line[0][4] - 'A' + 1) % 56;

	// ���� ���� ���� ����
	star[1] = n;

	// �𸣴� ĭ
	if (n == 0)
	{
		leftcnt++;
		leftn[leftcnt] = 1;
	}
	// �ƴ� ĭ
	else
	{
		used[n] = 1;
	}

	cin >> line[1];
	line[1][width] = '\0';
	for (int i = 0; i < 4; i++)
	{
		n = (line[1][2 * i + 1] - 'A' + 1) % 56;
		star[i + 2] = n;
		
		// �𸣴� ĭ
		if (n == 0)
		{
			leftcnt++;
			leftn[leftcnt] = i + 2;
		}
		// �ƴ� ĭ
		else
		{
			used[n] = 1;
		}
	}

	cin >> line[2];
	line[2][width] = '\0';
	n = (line[2][2] - 'A' + 1) % 56;
	star[6] = n;
	// �𸣴� ĭ
	if (n == 0)
	{
		leftcnt++;
		leftn[leftcnt] = 6;
	}
	// �ƴ� ĭ
	else
	{
		used[n] = 1;
	}

	n = (line[2][6] - 'A' + 1) % 56;
	star[7] = n;
	used[n] = (n == 0 ? 0 : 1);
	// �𸣴� ĭ
	if (n == 0)
	{
		leftcnt++;
		leftn[leftcnt] = 7;
	}
	// �ƴ� ĭ
	else
	{
		used[n] = 1;
	}

	cin >> line[3];
	line[3][width] = '\0';
	for (int i = 0; i < 4; i++)
	{
		n = (line[3][2 * i + 1] - 'A' + 1) % 56;
		star[i + 8] = n;
		// �𸣴� ĭ
		if (n == 0)
		{
			leftcnt++;
			leftn[leftcnt] = i + 8;
		}
		// �ƴ� ĭ
		else
		{
			used[n] = 1;
		}
	}

	cin >> line[4];
	line[4][width] = '\0';
	n = (line[4][4] - 'A' + 1) % 56;
	star[12] = n;
	// �𸣴� ĭ
	if (n == 0)
	{
		leftcnt++;
		leftn[leftcnt] = 12;
	}
	// �ƴ� ĭ
	else
	{
		used[n] = 1;
	}
}

/* ��� ��� */
void output(void)
{
	line[0][4] = 'A' + star[1] - 1;
	cout << line[0] << endl;

	for (int i = 0; i < 4; i++)
	{
		line[1][2 * i + 1] = 'A' + star[i + 2] - 1;
	}
	cout << line[1] << endl;

	line[2][2] = 'A' + star[6] - 1;
	line[2][6] = 'A' + star[7] - 1;
	cout << line[2] << endl;

	for (int i = 0; i < 4; i++)
	{
		line[3][2 * i + 1] = 'A' + star[i + 8] - 1;
	}
	cout << line[3] << endl;

	line[4][4] = 'A' + star[12] - 1;
	cout << line[4] << endl;

	exit(1);
}


int main()
{
	// ���׷� �Է¹���
	input();

	// �� ä���� ���ں��� ������� ä������
	backtracking(0);

	return 0;
}