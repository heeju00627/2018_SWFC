#include <stdio.h>
#define LOCAL 1

//Sliding Window


#define MAX 100010

int N;
long long M;

typedef struct _food {
	int full;
	int spicy;
}FOOD;

FOOD food[MAX];
int min_s = 1000000001;


void input(void)
{
	int i = 0;
	scanf("%d %lld", &N, &M);
	for (i = 0; i < N; i++)
		scanf("%d %d", &food[i].full, &food[i].spicy);
}
int find_max_spicy(int s, int e)
{
	int i = 0, tmp = 0;
	for (i = s; i <= e; i++)
	{
		if (tmp < food[i].spicy)
			tmp = food[i].spicy;
	}
	return tmp;
}
void myfunc(void)
{
	int head = 0, tail = 0;
	int tmp_s = 0;
	long long sum = 0;
	sum += food[head].full;
	tmp_s = food[head].spicy; //start position
	for (;;)
	{
		if (sum >= M) // statisfied 
		{
			if (min_s > tmp_s) //update
				min_s = tmp_s;
			if (head < tail) 
			{
				sum -= food[head].full;
				if (tmp_s == food[head].spicy)
					tmp_s = find_max_spicy(head + 1, tail);
				//if removed value has maximum spicy
				// find new max spicy within scope.

				head++;
			}
			else // if head == tail
			{
				tail++;
				if (tail == N)
					break;
				sum += food[tail].full;
				if (tmp_s < food[tail].spicy)
					tmp_s = food[tail].spicy;//update max spicy
			}
		}
		else
		{
			tail++;
			if (tail == N)
				break;
			sum += food[tail].full;
			if (tmp_s < food[tail].spicy)
				tmp_s = food[tail].spicy;
		}
	}

}

int main(void)
{
	if (LOCAL)freopen("input.txt", "r", stdin);
	
	input();
	myfunc();
	printf("%d\n", min_s);
	return 0;
}