#include <iostream>
using namespace std;

#define MAX 700

int N, M;
char map[MAX][MAX];

int Y[2];
int V[2];
int T[2];

int ymap[MAX][MAX];
int vmap[MAX][MAX];

int yQed[MAX][MAX];
int vQed[MAX][MAX];
int flag = 0;
int Q[MAX][3];
int Qs, Qe;

int FindLine(int row, int col, int val);
void writeNumVMap(int vrow, int vcol, int val);

void InQ(int row, int col, int val)
{
	Q[Qe][0] = row;
	Q[Qe][1] = col;
	Q[Qe][2] = val;
	if (Qe == MAX - 1)
		Qe = 0;
	else
		Qe++;
}
int DeQ(int *row, int *col, int *val)
{
	if (Qs == Qe)
		return -1;
	*row = Q[Qs][0];
	*col = Q[Qs][1];
	*val = Q[Qs][2];
	if (Qs == MAX - 1)
		Qs = 0;
	else
		Qs++;
	return 0;
}
void Input()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'Y')
			{
				Y[0] = i;
				Y[1] = j;
			}
			else if (map[i][j] == 'V')
			{
				V[0] = i;
				V[1] = j;
			}
			else if (map[i][j] == 'T')
			{
				T[0] = i;
				T[1] = j;
			}
		}
	}
}

void writeNumYMap_do(int yrow, int ycol, int val)
{
	if (flag)
		return;
	if (yrow == T[0] && ycol == T[1])
	{
		if (FindLine(yrow, ycol, val))
		{
			flag = 1;
			return;
		}
	}
	if (yrow - 1 > 0 && map[yrow - 1][ycol] != 'I'
		&& (yQed[yrow - 1][ycol] == 0 || (ymap[yrow - 1][ycol] > val + 1)))
	{
		if (FindLine(yrow - 1, ycol, val + 1))
		{
			InQ(yrow - 1, ycol, val + 1);
			yQed[yrow - 1][ycol] = 1;
			ymap[yrow - 1][ycol] = val + 1;
		}
	}
	if (yrow + 1 <= N &&  map[yrow + 1][ycol] != 'I'
		&& (yQed[yrow + 1][ycol] == 0 || (ymap[yrow + 1][ycol] > val + 1)))
	{
		if (FindLine(yrow + 1, ycol, val + 1))
		{
			InQ(yrow + 1, ycol, val + 1);
			yQed[yrow + 1][ycol] = 1;
			ymap[yrow + 1][ycol] = val + 1;
		}
	}
	if (ycol - 1 > 0 && map[yrow][ycol - 1] != 'I'
		&& (yQed[yrow][ycol - 1] == 0 || (ymap[yrow][ycol - 1] > val + 1)))
	{
		if (FindLine(yrow, ycol - 1, val + 1))
		{
			InQ(yrow, ycol - 1, val + 1);
			yQed[yrow][ycol - 1] = 1;
			ymap[yrow][ycol - 1] = val + 1;
		}
	}
	if (ycol + 1 <= M  && map[yrow][ycol + 1] != 'I' &&
		(yQed[yrow][ycol + 1] == 0 || (ymap[yrow][ycol + 1] > val + 1)))
	{
		if (FindLine(yrow, ycol + 1, val + 1))
		{
			InQ(yrow, ycol + 1, val + 1);
			yQed[yrow][ycol + 1] = 1;
			ymap[yrow][ycol + 1] = val + 1;
		}
	}
}
void writeNumYMap(int yrow, int ycol, int val)
{
	while (DeQ(&yrow, &ycol, &val) == 0)
		writeNumYMap_do(yrow, ycol, val);
}
void writeNumVMap_do(int row, int col, int val)
{
	vmap[row][col] = val;
	if (row - 1 > 0 && map[row - 1][col] != 'I'
		&& (vQed[row - 1][col] == 0 || (vmap[row - 1][col] > val + 1)))
	{
		InQ(row - 1, col, val + 1);
		vQed[row - 1][col] = 1;
	}
	if (row + 1 <= N &&  map[row + 1][col] != 'I'
		&& (vQed[row + 1][col] == 0 || (vmap[row + 1][col] > val + 1)))
	{
		InQ(row + 1, col, val + 1);
		vQed[row + 1][col] = 1;
	}
	if (col - 1 > 0 && map[row][col - 1] != 'I'
		&& (vQed[row][col - 1] == 0 || (vmap[row][col - 1] > val + 1)))
	{
		InQ(row, col - 1, val + 1);
		vQed[row][col - 1] = 1;
	}
	if (col + 1 <= M  && map[row][col + 1] != 'I' &&
		(vQed[row][col + 1] == 0 || (vmap[row][col + 1] > val + 1)))
	{
		InQ(row, col + 1, val + 1);
		vQed[row][col + 1] = 1;
	}
}
void writeNumVMap(int row, int col, int val)
{

	while (DeQ(&row, &col, &val) == 0)
		writeNumVMap_do(row, col, val);
}
int FindLine(int row, int col, int val)
{
	for (int i = row; i >= 1; i--)//up
	{
		if (map[i][col] == 'I')
			break;
		if (vmap[i][col] == val && vmap[i][col] > 0)
			return 0;
	}
	for (int i = row; i <= N; i++)//down
	{
		if (map[i][col] == 'I')
			break;
		if (vmap[i][col] == val && vmap[i][col] > 0)
			return 0;
	}
	for (int i = col; i <= M; i++)//right
	{
		if (map[row][i] == 'I')
			break;
		if (vmap[row][i] == val && vmap[row][i] > 0)
			return 0;
	}
	for (int i = col; i >= 1; i--)//left
	{
		if (map[row][i] == 'I')
			break;
		if (vmap[row][i] == val && vmap[row][i] > 0)
			return 0;
	}
	return 1;
}

int main(void)
{
	Input();
	yQed[Y[0]][Y[1]] = 1;
	vQed[V[0]][V[1]] = 1;
	InQ(V[0], V[1], 0);
	writeNumVMap(V[0], V[1], 0);
	Qs = Qe = 0;
	InQ(Y[0], Y[1], 0);
	writeNumYMap(Y[0], Y[1], 0);


	if (flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}