#include <iostream>
using namespace std;

// 교차로의 수(<=1000)
int n;
// 도로의 수(<=10000)
int m;

// 시작 교차로
int a;
// 도착 교차로
int b;
// 출발한 시간의 차이
int k;
// 오바마 방문 교차로 수
int g;
// 오바마 방문 교차로
int inter[1005];
// 이동 시간
int time[1005][1005];

int main(void)
{
	/* 입력 */
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






	/* 결과값 출력 */

	return 0;
}