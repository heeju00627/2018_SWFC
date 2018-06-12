#include <stdio.h>
#define LOCAL 1

#define MAX 505
#define QMAX MAX*MAX*3

int N, M;
char map[MAX][MAX];

typedef struct _pos {
	int row;
	int col;
}POS;
typedef struct _queue {
	POS pos;
	int cnt;
	int dir;
}QUE;

QUE Q[QMAX];
int rpt, wpt;
POS C, D;
int visit[MAX][MAX];
int min_t = -1;

void InQ(int row, int col, int cnt, int dir)
{
	QUE tmp;
	tmp.pos.row = row;
	tmp.pos.col = col;
	tmp.cnt = cnt;
	tmp.dir = dir;
	Q[wpt++] = tmp;
	if (wpt == QMAX)
		wpt = 0;
}
int DeQ(QUE *val)
{
	if (wpt == rpt)
		return -1;
	*val = Q[rpt++];
	if (rpt == QMAX)
		rpt = 0;
	return 0;
}

void input(void)
{
	int i = 0,j=0;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++)
	{
		map[i][0] = '0';
		scanf("%s", &map[i][1]);
		for (j = 1; j <= M; j++)
		{
			if (map[i][j] == 'C')
			{
				C.row = i;
				C.col = j;
			}
			else if (map[i][j] == 'D')
			{
				D.row = i;
				D.col = j;
			}
		}
	}
}
int check_fall(int row, int col, int dir)
{
	int i = 0;
	for (i = row;; i += dir)
	{
		if (map[i][col] == '\0' || map[i][col] == '0')
			return -1;
		if (map[i][col] == '#')
			return i-dir;
		if (map[i][col] == 'D') // C can meet D while falling. 
			return i;
	}
}
void myfunc_do(QUE val)
{
	int trow = 0, tcol = 0, tdir = 0;
	int tmp = 0;
	trow = val.pos.row;
	tcol = val.pos.col;
	tdir = val.dir;
	if (trow == D.row && tcol == D.col) // D met !
	{
		if (min_t == -1)
			min_t = val.cnt;
		else if (min_t > val.cnt)
			min_t = val.cnt;
		// can be found more less change that keep searching.
	}

	if (map[trow][tcol-1] == '.' || map[trow][tcol - 1] == 'D')//left
	{
		tmp = check_fall(trow, tcol-1, tdir);
		//falling before InQ
		if (tmp != -1)
		{
			if (visit[tmp][tcol - 1] == 0 || visit[tmp][tcol - 1] > val.cnt + 1)
			{
				InQ(tmp, tcol - 1, val.cnt, tdir);
				visit[tmp][tcol - 1] = val.cnt + 1;
			}
		}
	}
	if (map[trow][tcol + 1] == '.' || map[trow][tcol + 1] == 'D')//right
	{
		tmp = check_fall(trow, tcol + 1, tdir);
		if (tmp != -1)
		{
			if (visit[tmp][tcol + 1] == 0 || visit[tmp][tcol + 1] > val.cnt + 1)
			{
				InQ(tmp, tcol + 1, val.cnt, tdir);
				visit[tmp][tcol + 1] = val.cnt + 1;
			}
		}
	}
	if (min_t == -1 || val.cnt + 1 < min_t)//change direction
	{
		tmp = check_fall(trow, tcol, tdir*(-1));
		if (tmp != -1)
		{
			if (visit[tmp][tcol] == 0 || visit[tmp][tcol] > val.cnt + 2)
			{
				InQ(tmp, tcol, val.cnt + 1, tdir*(-1));
				visit[tmp][tcol] = val.cnt + 2;
			}
		}
	}
}
void myfunc(void)
{
	QUE tmp;
	int init;
	tmp.pos = C;
	tmp.cnt = 0;
	tmp.dir = 1;
	//dir == 1 means that gravity actives to down.
	// -1 means up.
	init = check_fall(tmp.pos.row, tmp.pos.col, tmp.dir);
	if (init == -1)
		return;
	//check before start
	// some cases 'C' start with falling.
	// after finishing to fall, start there(if alive)
	tmp.pos.row = init;
	visit[tmp.pos.row][tmp.pos.col]= 1;
	// visit has how many changed direction of gravity.
	// but, to distingish not visited, times of changing increased by 1.

	InQ(tmp.pos.row, tmp.pos.col, tmp.cnt, tmp.dir);
	while (DeQ(&tmp) == 0) // this is BFS. 
		myfunc_do(tmp);
}
int main(void)
{
	if (LOCAL) freopen("input.txt", "r", stdin);
	input();

	myfunc();
	printf("%d\n", min_t);

	return 0;
}