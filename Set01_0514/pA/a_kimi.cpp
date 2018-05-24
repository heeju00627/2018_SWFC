#include <iostream>
using namespace std;

// ��ü �ð�
int t;
// ù��° �������� ��
int n;
// ù��° �� ����(ù ���ڳ�, ���� �ð�)
int ninfo[101][2] = { 0, };
// �ι�° �������� ��
int m;
// �ι�° �� ����(ù ���ڳ�, ���� �ð�)
int minfo[101][2] = { 0, };

/* coconut */
int coco(int k)
{
	int first = 0;
	int second = 0;

	// �� ���ڳ� ���
	for (int i = 0; i < n; i++)
	{
		int a = ninfo[i][0];
		int b = ninfo[i][1];

		if (k >= a)
		{
			first += 1 + (k - a) / b;
		}
	}

	// �ι�° ���� �־��� �ð�
	int tk = t - k;

	// �� ���ڳ� ���
	for (int i = 0; i < m; i++)
	{
		int c = minfo[i][0];
		int d = minfo[i][1];

		if (tk >= c)
		{
			second += 1 + (tk - c) / d;
		}
	}

	// �� ���ڳ� ����(ù��° �� ����) �� Ŭ ��
	if (first > second)
	{
		return 1;
	}

	// �� ���ڳ� ����(�ι�° �� ����) �� Ŭ ��
	else if (first < second)
	{
		return 2;
	}

	// �� ���ڳӰ� �� ���ڳ��� ���� ��
	else
	{
		return 0;
	}
}

/* binary search */
int binary_search(int t)
{
	int start = 0;
	int end = t;
	int mid;

	int co;

	// �� �� �� ���� ���� ����
	while (start <= end)
	{
		mid = (start + end) / 2;

		switch (co = coco(mid))
		{
		// ù��° �� ����
		case 1:
			end = mid - 1;
			break;
		// �ι�° �� ����
		case 2:
			start = mid + 1;
			break;
		// ����
		case 0:
			return mid;
		}
	}

	switch (co)
	{
	case 1:
		while (co == 1)
		{
			mid = mid - 1;
			co = coco(mid);
		}
		// �ι�°�� �����ϴ� ����
		return mid;
	case 2:
		while (co == 2)
		{
			mid = mid + 1;
			co = coco(mid);
		}
		// ù��°�� �����ϴ� ���� - 1
		return mid - 1;
	}

	return mid;
}

int main(void)
{
	
	cin >> t;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ninfo[i][0] >> ninfo[i][1];
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> minfo[i][0] >> minfo[i][1];
	}

	// ��ü �ð� t�� k�ʿ� t-k�ʷ� �����Ͽ� ������
	int answer = binary_search(t);
	
	cout << answer << endl;

	return 0;
}