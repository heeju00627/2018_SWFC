#include <iostream>
using namespace std;

#define MAX 102
int T, N, M;
int A[MAX], B[MAX], C[MAX], D[MAX];
int timeM[35];
int tpt;

void Input()
{
	int tt = 0;
	cin >> T >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i] >> B[i];
	cin >> M;
	for (int i = 1; i <= M; i++)
		cin >> C[i] >> D[i];
	tt = T;
	tpt = 0;
	for ( tpt = 0; tpt < 35; tpt++)
	{
		timeM[tpt] = tt;
		if (timeM[tpt - 1] == timeM[tpt])
			break;
		if (tt % 2)
			tt = tt / 2 + 1;
		else
			tt = tt / 2;
	}
}
int CalcCo1(int sec)
{
	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		if (sec >= A[i])
			sum += ((sec - A[i]) / B[i]) + 1;
	}
	return sum;
}
int CalcCo2(int sec)
{
	int sum = 0;
	for (int i = 1; i <= M; i++)
	{
		if (sec >= C[i])
			sum += ((sec - C[i]) / D[i]) + 1;
	}
	return sum;
}

int main()
{
	Input();
	int tmp1 = 0;
	int tmp2 = 0;
	int sec1 = T/2;
	int sec2 = T - sec1;
	int i = 0;
	for(i=1; i<tpt; i++)
	{
		tmp1 = CalcCo1(sec1);
		tmp2 = CalcCo2(sec2);
		if (tmp1 > tmp2)
		{
			sec1 -= timeM[i];
			sec2 = T - sec1;
		}
		else if (tmp1 < tmp2)
		{
			sec2 -= timeM[i];
			sec1 = T - sec2;
		}
		else
			break;

	}
	cout << sec1 << endl;
	return 0;
}