#include <iostream>
using namespace std;

/***************************************
 . . . . 1 . . . .
 . 2 . 3 . 4 . 5 .
 . . 6 . . . 7 . .
 . 8 . 9 . 10. 11.
 . . . . 12. . . .
***************************************/

char star[6][10];
int map[13];
int alpha[13];
int vola[13];

void Input(void)
{
	int tmp;
	int pt = 1;
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cin >> star[i][j];
			if (star[i][j] == '.')
				tmp = -1;
			else if (star[i][j] == 'x')
			{
				tmp = 0;
				vola[pt] = 0;
				map[pt++] = 0;
			}
			else
			{
				tmp = star[i][j] - 'A' + 1;
				alpha[tmp] = 1;
				vola[pt] = 1;
				map[pt++] = tmp;
			}
		}
	}
}
int checkstar()
{
	if (map[1] + map[3] + map[6] + map[8] != 26)
		return 0;
	if (map[1] + map[4] + map[7] + map[11] != 26)
		return 0;
	if (map[2] + map[3] + map[4] + map[5] != 26)
		return 0;
	if (map[8] + map[9] + map[10] + map[11] != 26)
		return 0;
	if (map[2] + map[6] + map[9] + map[12] != 26)
		return 0;
	if (map[5] + map[7] + map[10] + map[12] != 26)
		return 0;
	return 1;
}
void printmap()
{
	for (int i = 1; i <= 12; i++)
		cout << map[i] << ' ';
	cout << endl;
}
int myfunc(int n)
{
	//if(map[1] == 5 && map[5] == 12)
	//	printmap();
	int Q[13];
	int Qpt = 0;
	if (n == 13)
		return 0;
	if (map[n] == 0)
	{
		for (int i = 1; i <= 12; i++)
		{
			if (alpha[i] == 0)
				Q[Qpt++] = i;
		}
		for (int i = 0; i < Qpt; i++)
		{
			map[n] = Q[i];
			alpha[Q[i]] = 1;
			if (myfunc(n + 1))
				return 1;
			alpha[Q[i]] = 0;
		}
	}
	else
		myfunc(n + 1);
	if (checkstar())
		return 1;
	if(vola[n] == 0)
		map[n] = 0;
	return 0;
}

int main(void)
{
	Input();
	myfunc(1);

	star[1][5] = map[1] + 'A' - 1;
	star[2][2] = map[2] + 'A' - 1;
	star[2][4] = map[3] + 'A' - 1;
	star[2][6] = map[4] + 'A' - 1;
	star[2][8] = map[5] + 'A' - 1;
	star[3][3] = map[6] + 'A' - 1;
	star[3][7] = map[7] + 'A' - 1;
	star[4][2] = map[8] + 'A' - 1;
	star[4][4] = map[9] + 'A' - 1;
	star[4][6] = map[10] + 'A' - 1;
	star[4][8] = map[11] + 'A' - 1;
	star[5][5] = map[12] + 'A' - 1;
	
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cout << star[i][j];
		}
		cout << endl;
	}
	return 0;
}