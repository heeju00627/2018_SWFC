#include <iostream>

using namespace std;

#define MAX 128

int N;
int map[MAX][MAX];
int b_cnt; // blue paper's count
int w_cnt; // white paper's count


void Input()
{
	int tmp;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	}
}
int check_color(int r, int c, int n)
// return -1 : it has mixed color.
// return 0 : it has white color.
// return 1 : it has blue color.
{
	int cur = map[r][c]; // check current color is blue or white
	for (int i = r; i < r + n; i++)
	{
		for (int j = c; j < c + n; j++)
		{
			if (map[i][j] != cur) // if different color is appered...
				return -1;
		}
	}
	return cur; // return it's color. (0: white, 1: blue)
}
void myfunc(int r, int c, int n)
{
	int tmp = check_color(r, c, n); // check its color in 'n' scope.
	if (tmp== -1) // if not, cut the paper into 4 pieces. 
	{
		myfunc(r, c, n / 2); 
		myfunc(r, c + n / 2, n / 2);
		myfunc(r + n / 2, c, n / 2);
		myfunc(r + n / 2, c + n / 2, n / 2); // call recursively for each pieces.
	}
	else
	{
		if (tmp == 0) // white only
			w_cnt++;
		else          // blue only
			b_cnt++;
	}
}
int main(void)
{
	Input();

	myfunc(0, 0, N); // start position and N
	cout << w_cnt << endl << b_cnt << endl;
  	return 0;
}