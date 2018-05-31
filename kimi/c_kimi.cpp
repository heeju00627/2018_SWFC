#include <iostream>
#define width 9
#define height 5
#define num 12
using namespace std;

// 매직 스타 형태
int point[21] = { 4, 4, 0, 1, 1, 1, 1, 1, 0, 2, 3, 2, 0, 1, 1, 1, 1, 1, 0, 4, 4 };
// 입력값
char line[height][width + 1];

// 숫자 네 개로 이루어진 줄 번호
int sumpos[6][4] = { {1, 3, 6, 8}, {1, 4, 7, 11}, {2, 3, 4, 5},
					{8, 9, 10, 11}, {2, 6, 9, 12}, {5, 7, 10, 12} };

// 실제 숫자
int star[num + 1];
// 사용된 숫자
int used[num + 1];
// 채워지지 않은 자리
int leftn[num + 1];
// 안 쓴 숫자 수
int leftcnt;

void input();
void output();

void backtracking(int k)
{
	// 모든 숫자를 다 채워넣음
	if (k == leftcnt)
	{
		int sum;

		for (int i = 0; i < 6; i++)
		{
			sum = 0;
			// 한줄씩 sum 계산
			for (int j = 0; j < 4; j++)
			{
				int pos = sumpos[i][j];
				sum += star[pos];
			}

			// 잘못된 채워나감
			if (sum != 26)
			{
				return;
			}
		}

		// 출력
		output();
	}

	// 숫자를 채워나가자
	for (int i = 1; i <= num; i++)
	{
		// 사용하지 않은 i를
		if (used[i] == 0)
		{
			used[i] = 1;

			// 아직 채우지 않은 cur번째 star 칸에
			int cur = leftn[k + 1];
			star[cur] = i;
			backtracking(k + 1);
			
			used[i] = 0;
		}
	}
}

/* 정보 입력 */
void input(void)
{
	int n;

	cin >> line[0];
	line[0][width] = '\0';
	n = (line[0][4] - 'A' + 1) % 56;

	// 지금 적힌 숫자 저장
	star[1] = n;

	// 모르는 칸
	if (n == 0)
	{
		leftcnt++;
		leftn[leftcnt] = 1;
	}
	// 아는 칸
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
		
		// 모르는 칸
		if (n == 0)
		{
			leftcnt++;
			leftn[leftcnt] = i + 2;
		}
		// 아는 칸
		else
		{
			used[n] = 1;
		}
	}

	cin >> line[2];
	line[2][width] = '\0';
	n = (line[2][2] - 'A' + 1) % 56;
	star[6] = n;
	// 모르는 칸
	if (n == 0)
	{
		leftcnt++;
		leftn[leftcnt] = 6;
	}
	// 아는 칸
	else
	{
		used[n] = 1;
	}

	n = (line[2][6] - 'A' + 1) % 56;
	star[7] = n;
	used[n] = (n == 0 ? 0 : 1);
	// 모르는 칸
	if (n == 0)
	{
		leftcnt++;
		leftn[leftcnt] = 7;
	}
	// 아는 칸
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
		// 모르는 칸
		if (n == 0)
		{
			leftcnt++;
			leftn[leftcnt] = i + 8;
		}
		// 아는 칸
		else
		{
			used[n] = 1;
		}
	}

	cin >> line[4];
	line[4][width] = '\0';
	n = (line[4][4] - 'A' + 1) % 56;
	star[12] = n;
	// 모르는 칸
	if (n == 0)
	{
		leftcnt++;
		leftn[leftcnt] = 12;
	}
	// 아는 칸
	else
	{
		used[n] = 1;
	}
}

/* 결과 출력 */
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
	// 헥사그램 입력받음
	input();

	// 안 채워진 숫자부터 순서대로 채워나감
	backtracking(0);

	return 0;
}