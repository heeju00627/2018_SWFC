
#if 01
#include <iostream>
using namespace std;

#define MAX 1505

int R, C;
char ori_map[MAX][MAX];
int map[MAX][MAX];
int boy[2], girl[2];
int Qed[MAX][MAX];
int met;

typedef struct _q
{
	int r;
	int c;
	_q *next;
}QUE;
QUE *rq[2] = { NULL,NULL };
QUE *wq[2] = { NULL,NULL };

void InQ(int row, int col, QUE **rq, QUE **wq)
{
	QUE *q = new QUE;
	q->next = NULL;
	if (*wq == NULL)
		*rq = q;
	else
		(*wq)->next = q;
	*wq = q;	
	(*wq)->r = row;
	(*wq)->c = col;
}
int DeQ(int *row, int *col, QUE **rq, QUE **wq)
{
	if (*rq == NULL)
		return -1;
	
	*row = (*rq)->r;
	*col = (*rq)->c;
	QUE *t = (*rq);
	*rq = (*rq)->next;
	if (*rq == NULL)
		*wq = NULL;
	delete t;
	return 0;
}
	

void input(void)
{
	cin >> R >> C;
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cin >> ori_map[i][j];
			if (ori_map[i][j] == 'L')
			{
				if (boy[0] == 0)
				{
					boy[0] = i;
					boy[1] = j;
				}
				else
				{
					girl[0] = i;
					girl[1] = j;
				}
			}
		}
	}
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
			map[i][j] = -1;
	}
}
void debug_print(void)
{
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void drawmap_do(int row, int col)
{
	int rows[4] = { row - 1, row, row + 1 ,row };
	int cols[4] = { col, col + 1, col, col - 1 };
	// up, right, down, left
	for (int i = 0; i < 4; i++)
	{
		/* 1. next '.'
		1-1. cur 0 or 1
		1-1-1. next -1 -> 0 update and go
		1-1-2. next 0  -> stop
		1-2. cur >=2
		1-2-1. next -1 -> 0 update and go
		1-2-2. next 0 -> go

		2. next 'X'
		2-1. next -1 -> cur+1 update and go
		2-2. next n
		2-2-1. n>c+1 -> cur+1 update and go
		2-2-2. n<c-1 -> go
		2-2-3. other(c-1<=n<=c+1) -> stop
		*/
		if (ori_map[rows[i]][cols[i]] == '.' ||
			ori_map[rows[i]][cols[i]] == 'L') //1
		{
			if (map[row][col] <= 1) // 1-1
			{
				if (map[rows[i]][cols[i]] == -1) // 1-1-1. 
				{
					map[rows[i]][cols[i]] = 0;
					InQ(rows[i], cols[i], &rq[0], &wq[0]);
				}
				else if (map[rows[i]][cols[i]] == 0)//1-1-2.
				{

				}
				else
				{
					cout << "what case of 1-1?" << endl;
				}
			}
			else if (map[row][col] >= 2) //1-2
			{
				if (map[rows[i]][cols[i]] == -1) // 1-2-1. 
				{
					map[rows[i]][cols[i]] = 0;
					InQ(rows[i], cols[i], &rq[0], &wq[0]);
				}
				else if (map[rows[i]][cols[i]] == 0)//1-1-2.
				{
					InQ(rows[i], cols[i], &rq[0], &wq[0]);
				}
				else
				{
					cout << "what case of 1-2?" << endl;
				}
			}
			else
			{
				cout << "what case of 1?" << endl;
			}
		}
		else if (ori_map[rows[i]][cols[i]] == 'X') //2
		{
			if (map[rows[i]][cols[i]] == -1) //2-1
			{
				map[rows[i]][cols[i]] = map[row][col] + 1;
				InQ(rows[i], cols[i], &rq[0], &wq[0]);
			}
			else if (map[rows[i]][cols[i]] > map[row][col] + 1) // 2-2-1.
			{
				map[rows[i]][cols[i]] = map[row][col] + 1;
				InQ(rows[i], cols[i], &rq[0], &wq[0]);
			}
			else if (map[rows[i]][cols[i]] < map[row][col] - 1) // 2-2-2.
			{
				InQ(rows[i], cols[i], &rq[0], &wq[0]);
			}
			else //2-2-3.
			{

			}
		}
		else if (ori_map[rows[i]][cols[i]] == '\0')
		{

		}
		else
		{
			cout << "what case of overall?" << endl;
		}
	}
}
void drawmap(int row, int col)
{	
	//debug_print();
	while (DeQ(&row, &col, &rq[0], &wq[0]) == 0)
		drawmap_do(row, col);
}
void findroute_do(int row, int col, int t)
{
	if (met > 0)
		return;
	int rows[4] = { row - 1, row, row + 1 ,row };
	int cols[4] = { col, col + 1, col, col - 1 };
	// up, right, down, left
	for (int i = 0; i < 4; i++)
	{
		if (rows[i] == girl[0] && cols[i] == girl[1]) // found
		{
			met = t;
			return;
		}

		if (Qed[rows[i]][cols[i]] == 0)
		{
			Qed[rows[i]][cols[i]] = 1;
			if (map[rows[i]][cols[i]] != -1)
			{
				if (map[rows[i]][cols[i]] <= t)
					InQ(rows[i], cols[i], &rq[0], &wq[0]);
				else if (map[rows[i]][cols[i]] == t + 1)
					InQ(rows[i], cols[i], &rq[1], &wq[1]);
			}
		}
	}
}
void findroute(int row, int col, int t)
{	
	while (DeQ(&row, &col, &rq[0], &wq[0]) == 0)
	{
		findroute_do(row, col, t);
	}
	while (DeQ(&row, &col, &rq[1], &wq[1]) == 0)
	{
		InQ(row, col, &rq[0], &wq[0]);
	}
	while (DeQ(&row, &col, &rq[0], &wq[0]) == 0)
	{
		findroute(row, col, t+1);
	}
}
int main(void)
{
	input();
	map[boy[0]][boy[1]] = 0;
	InQ(boy[0], boy[1], &rq[0], &wq[0]);
	drawmap(boy[0], boy[1]);
	Qed[boy[0]][boy[1]] = 1;
	InQ(boy[0], boy[1], &rq[0], &wq[0]);
	findroute(boy[0], boy[1], 0);
	cout << met << endl;
	return 0;
}
#endif


#if 0
#include <iostream>
using namespace std;

#define MAX 1505

int R, C;
char ori_map[MAX][MAX];
int map[MAX][MAX];
int boy[2], girl[2];
int Q[MAX * 2][2][2];
int rq[2], wq[2];
int Qed[MAX][MAX];
int met;


void InQ(int row, int col,int Qnum, int *rq, int *wq)
{
	Q[*wq][Qnum][0] = row;
	Q[*wq][Qnum][1] = col;
	(*wq)++;
	if (*wq == MAX * 2)
		*wq = 0;
}
int DeQ(int *row, int *col, int Qnum, int *rq, int *wq)
{
	if (*rq == *wq)
		return -1;
	*row = Q[*rq][Qnum][0];
	*col = Q[*rq][Qnum][1];
	(*rq)++;
	if (*rq == MAX * 2)
		*rq = 0;
	return 0;
}

void input(void)
{
	cin >> R >> C;
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cin >> ori_map[i][j];
			if (ori_map[i][j] == 'L')
			{
				if (boy[0] == 0)
				{
					boy[0] = i;
					boy[1] = j;
				}
				else
				{
					girl[0] = i;
					girl[1] = j;
				}
			}
		}
	}
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
			map[i][j] = -1;
	}
}
void drawmap(int row, int col)
{
	int rows[4] = { row - 1, row, row + 1 ,row };
	int cols[4] = { col, col + 1, col, col - 1 };
	// up, right, down, left
	for (int i = 0; i < 4; i++)
	{
		/* 1. next '.'
		1-1. cur 0 or 1
		1-1-1. next -1 -> 0 update and go
		1-1-2. next 0  -> stop
		1-2. cur >=2
		1-2-1. next -1 -> 0 update and go
		1-2-2. next 0 -> go

		2. next 'X'
		2-1. next -1 -> cur+1 update and go
		2-2. next n
		2-2-1. n>c+1 -> cur+1 update and go
		2-2-2. n<c-1 -> go
		2-2-3. other(c-1<=n<=c+1) -> stop
		*/
		if (ori_map[rows[i]][cols[i]] == '.' ||
			ori_map[rows[i]][cols[i]] == 'L') //1
		{
			if (map[row][col] <= 1) // 1-1
			{
				if (map[rows[i]][cols[i]] == -1) // 1-1-1. 
				{
					map[rows[i]][cols[i]] = 0;
					InQ(rows[i], cols[i],0, &rq[0], &wq[0]);
				}
				else if (map[rows[i]][cols[i]] == 0)//1-1-2.
				{

				}
				else
				{
					cout << "what case of 1-1?" << endl;
				}
			}
			else if (map[row][col] >= 2) //1-2
			{
				if (map[rows[i]][cols[i]] == -1) // 1-2-1. 
				{
					map[rows[i]][cols[i]] = 0;
					InQ(rows[i], cols[i], 0, &rq[0], &wq[0]);
				}
				else if (map[rows[i]][cols[i]] == 0)//1-1-2.
				{
					InQ(rows[i], cols[i], 0, &rq[0], &wq[0]);
				}
				else
				{
					cout << "what case of 1-2?" << endl;
				}
			}
			else
			{
				cout << "what case of 1?" << endl;
			}
		}
		else if (ori_map[rows[i]][cols[i]] == 'X') //2
		{
			if (map[rows[i]][cols[i]] == -1) //2-1
			{
				map[rows[i]][cols[i]] = map[row][col] + 1;
				InQ(rows[i], cols[i], 0, &rq[0], &wq[0]);
			}
			else if (map[rows[i]][cols[i]] > map[row][col] + 1) // 2-2-1.
			{
				map[rows[i]][cols[i]] = map[row][col] + 1;
				InQ(rows[i], cols[i], 0, &rq[0], &wq[0]);
			}
			else if (map[rows[i]][cols[i]] < map[row][col] - 1) // 2-2-2.
			{
				InQ(rows[i], cols[i], 0, &rq[0], &wq[0]);
			}
			else //2-2-3.
			{

			}
		}
		else if (ori_map[rows[i]][cols[i]] == '\0')
		{

		}
		else
		{
			cout << "what case of overall?" << endl;
		}
	}
	//debug_print();
	if (DeQ(&row, &col, 0, &rq[0], &wq[0]) == 0)
		drawmap(row, col);
}
void findroute(int row, int col, int t)
{
	if (met > 0)
		return;
	int rows[4] = { row - 1, row, row + 1 ,row };
	int cols[4] = { col, col + 1, col, col - 1 };
	// up, right, down, left
	for (int i = 0; i < 4; i++)
	{
		if (rows[i] == girl[0] && cols[i] == girl[1]) // found
		{
			met = t;
			return;
		}

		if (Qed[rows[i]][cols[i]] == 0)
		{
			Qed[rows[i]][cols[i]] = 1;
			if (map[rows[i]][cols[i]] != -1)
			{
				if (map[rows[i]][cols[i]] <= t)
					InQ(rows[i], cols[i], 0, &rq[0], &wq[0]);
				else if (map[rows[i]][cols[i]] == t + 1)
					InQ(rows[i], cols[i], 1, &rq[1], &wq[1]);
			}
		}
	}
	while (DeQ(&row, &col, 0, &rq[0], &wq[0]) == 0)
	{
		findroute(row, col, t);
	}
	while (DeQ(&row, &col, 1, &rq[1], &wq[1]) == 0)
	{
		InQ(row, col, 0, &rq[0], &wq[0]);
	}
	while (DeQ(&row, &col, 0, &rq[0], &wq[0]) == 0)
	{
		findroute(row, col, t + 1);
	}
}
int main(void)
{
	input();
	map[boy[0]][boy[1]] = 0;
	drawmap(boy[0], boy[1]);
	Qed[boy[0]][boy[1]] = 1;
	findroute(boy[0], boy[1], 0);
	cout << met << endl;
	return 0;
}
#endif