#include <iostream>

using namespace std;

#define MAXNODE 1002
#define MAXROAD 10002

int N, M; // node , road
int A, B, K, G; // start , end , start_time, ohbama's num of node
int ohbama[MAXNODE][2]; // time, node
int roadMap[MAXNODE][MAXNODE]; // road time
int timeMap[MAXNODE]; // min time map

int Q[MAXNODE];
bool Qed[MAXNODE];
int Qs, Qe;

void InQ(int val)
{
	Q[Qe] = val;
	if (Qe == MAXNODE)
		Qe = 0;
	else
		Qe++;
}
int DeQ(void)
{
	int ret = 0;
	if (Qs == Qe)
		return -1;
	else
	{
		ret = Q[Qs];
		if (Qs == MAXNODE)
			Qs = 0;
		else
			Qs++;
		return ret;
	}
}

void Input(void)
{
	for (int i = 0; i < MAXNODE; i++)
	{
		timeMap[i] = 9999999;
		for (int j = 0; j < MAXNODE; j++)
		{
			roadMap[i][j] = -1; //disconnected road is -1
		}
	}
	int a, b;
	cin >> N >> M;
	cin >> A >> B >> K >> G;

	for (int i = 1; i <= G; i++)
		cin >> ohbama[i][1];	//input node num
	for (int i = 1; i <= M; i++)
	{
		cin >> a >> b;
		cin >> roadMap[a][b];
		roadMap[b][a] = roadMap[a][b];
	}
	ohbama[1][0] = 0;	// ohbama's starting time is 0
	for (int i = 2; i <= G; i++)
		ohbama[i][0] = ohbama[i-1][0] + roadMap[ohbama[i][1]][ohbama[i - 1][1]];
	//ohbama's next node time of taking
	timeMap[A] = 0; // Tak's start time is 0 (w/o K pending)
}		
int ohbamaCheck(int ctime, int src, int dst)
{
	for (int i = 1; i <= G; i++)
	{
		if (ctime < ohbama[i][0])
		{
			if (src == ohbama[i][1] && dst == ohbama[i - 1][1] ||
				src == ohbama[i - 1][1] && dst == ohbama[i][1])
			{
				return ohbama[i][0] - ctime;
			}
			else
				return 0;
		}
	}
	return 0;
} // check road's availity returns waiting time
void myFunc(int ctime, int n_num)
{
	int tmp = 0;
	for (int i = 1; i <= N; i++)
	{
		if (roadMap[n_num][i] != -1)
		{
			tmp = timeMap[n_num] + roadMap[n_num][i] + ohbamaCheck(ctime, n_num, i);
			// like Dijkstra, with ohbamacheck
			if (tmp < timeMap[i])
			{
				timeMap[i] = tmp;
				if (!Qed[i])
				{
					InQ(i);
					Qed[i] = 1;
				}
			}

			
		}
	}
	tmp = DeQ();
	if (tmp != -1)
	{
		Qed[tmp] = 0;
		myFunc(K + timeMap[tmp], tmp); // ctime is including K time and its min taking time.
	}
}
int main(void)
{
	Input();

	myFunc(K, A);
	cout << timeMap[B];
	return 0;
}