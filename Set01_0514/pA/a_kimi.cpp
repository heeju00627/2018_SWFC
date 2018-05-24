#include <iostream>
using namespace std;

// 전체 시간
int t;
// 첫번째 원숭이의 수
int n;
// 첫번째 종 정보(첫 코코넛, 이후 시간)
int ninfo[101][2] = { 0, };
// 두번째 원숭이의 수
int m;
// 두번째 종 정보(첫 코코넛, 이후 시간)
int minfo[101][2] = { 0, };

/* coconut */
int coco(int k)
{
	int first = 0;
	int second = 0;

	// 딴 코코넛 계산
	for (int i = 0; i < n; i++)
	{
		int a = ninfo[i][0];
		int b = ninfo[i][1];

		if (k >= a)
		{
			first += 1 + (k - a) / b;
		}
	}

	// 두번째 종에 주어진 시간
	int tk = t - k;

	// 깐 코코넛 계산
	for (int i = 0; i < m; i++)
	{
		int c = minfo[i][0];
		int d = minfo[i][1];

		if (tk >= c)
		{
			second += 1 + (tk - c) / d;
		}
	}

	// 딴 코코넛 수가(첫번째 종 열일) 더 클 때
	if (first > second)
	{
		return 1;
	}

	// 깐 코코넛 수가(두번째 종 열일) 더 클 때
	else if (first < second)
	{
		return 2;
	}

	// 딴 코코넛과 깐 코코넛이 같을 때
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

	// 깐 게 더 많을 수는 없지
	while (start <= end)
	{
		mid = (start + end) / 2;

		switch (co = coco(mid))
		{
		// 첫번째 종 열일
		case 1:
			end = mid - 1;
			break;
		// 두번째 종 열일
		case 2:
			start = mid + 1;
			break;
		// 정답
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
		// 두번째가 열일하는 순간
		return mid;
	case 2:
		while (co == 2)
		{
			mid = mid + 1;
			co = coco(mid);
		}
		// 첫번째가 열일하는 순간 - 1
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

	// 전체 시간 t를 k초와 t-k초로 분할하여 나눠씀
	int answer = binary_search(t);
	
	cout << answer << endl;

	return 0;
}