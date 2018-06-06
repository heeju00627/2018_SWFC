#include <stdio.h>

char sky[1504][1504];
// 견우 : 벽-A, 그냥-a
// 직녀 : 벽-B, 그냥-b
// 나머지 : 벽-Z, 그냥-z
// 바깥벽 : I
// 기본값은 소문자

int r, c;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int queue[1300010][2], head, tail, last_head;
int temp_queue[1300010][2], temp_head, temp_tail;

int temp_enqueue(int x, int y)
{
	temp_queue[temp_head][0] = x;
	temp_queue[temp_head][1] = y;
	temp_head++;
	if (temp_head > 1300000) temp_head = 0;
	return 0;
}
int temp_dequeue(int *x, int *y)
{
	*x = temp_queue[temp_tail][0];
	*y = temp_queue[temp_tail][1];
	temp_tail++;
	if (temp_tail > 1300000) temp_tail = 0;
	return 0;
}

int enqueue(int x, int y)
{
	queue[head][0] = x;
	queue[head][1] = y;
	head++;
	if (head > 1300000) head = 0;
	return 0;
}
int dequeue(int *x, int *y)
{
	*x = queue[tail][0];
	*y = queue[tail][1];
	tail++;
	if (tail > 1300000) tail = 0;
	return 0;
}

int infection(int x, int y, char att)
{
	char att_cap = att - ('a' - 'A');
	int i, j;
	if (sky[y][x] == 'z'){
		sky[y][x] = att;
		temp_enqueue(x, y);
	}
	else if (sky[y][x] == 'Z'){
		sky[y][x] = att_cap;
		temp_enqueue(x, y);
	}
	while (1){
		if (temp_tail == temp_head) break;
		temp_dequeue(&x, &y);
		for (i = 0; i < 4; i++){
			if (sky[y + dy[i]][x + dx[i]] == 'z'){
				sky[y + dy[i]][x + dx[i]] = att;
				temp_enqueue(x + dx[i], y + dy[i]);
			}
			else if (sky[y + dy[i]][x + dx[i]] == 'Z'){
				sky[y + dy[i]][x + dx[i]] = att_cap;
				temp_enqueue(x + dx[i], y + dy[i]);
			}
		}
	}
	return 0;
}

int bfs_setting(int x, int y, char c)
{
	char c_cap = c - ('a' - 'A');
	int i, j;
	enqueue(x, y);
	while (1){
		if (tail == head) break;
		dequeue(&x, &y);
		for (i = 0; i < 4; i++){
			if (sky[y + dy[i]][x + dx[i]] == '.'){
				sky[y + dy[i]][x + dx[i]] = c;
				enqueue(x + dx[i], y + dy[i]);
			}
			else if (sky[y + dy[i]][x + dx[i]] == 'X'){
				sky[y][x] = c_cap;
			}
		}
	}
	return 0;
}
int check(int x, int y)
{
	int i;
	for (i=0; i<4; i++){
		if ((sky[y][x] == 'A' && (sky[y + dy[i]][x + dx[i]] == 'B' || sky[y + dy[i]][x + dx[i]] == 'b')) || (sky[y][x] == 'B' && (sky[y + dy[i]][x + dx[i]] == 'A' || sky[y + dy[i]][x + dx[i]] == 'a'))){
			return 1;
		}
	}
	return 0;
}

int bfs()
{
	int i, j, x, y, cnt=1;
	char temp_c;
	last_head = head;
	while (1){
		if (tail == head) break;
		if (tail == last_head){ // level finish
			last_head = head;
			for (i=tail; i<=head; i++){
				for (j=0; j<4; j++){
					if ((sky[queue[i][1]][queue[i][0]] == 'A' || sky[queue[i][1]][queue[i][0]] == 'B' || sky[queue[i][1]][queue[i][0]] == 'a' || sky[queue[i][1]][queue[i][0]] == 'b') 
							&& (sky[queue[i][1]+dy[j]][queue[i][0]+dx[j]] == 'Z' || sky[queue[i][1]+dy[j]][queue[i][0]+dx[j]] == 'z')){
						if (sky[queue[i][1]][queue[i][0]] == 'A' || sky[queue[i][1]][queue[i][0]] == 'B') temp_c = sky[queue[i][1]][queue[i][0]]+('a'-'A');
						else temp_c = sky[queue[i][1]][queue[i][0]];
						infection(queue[i][0]+dx[j], queue[i][1]+dy[j], temp_c);
					}
				}
			}
			for (i=tail; i<=head; i++){
				if (check(queue[i][0], queue[i][1]))
					return cnt;
			}
			cnt++;
		}
		dequeue(&x, &y);
		for (i = 0; i < 4; i++){
			if ((sky[y][x] == 'A' && (sky[y + dy[i]][x + dx[i]] == 'B' || sky[y + dy[i]][x + dx[i]] == 'b')) || (sky[y][x] == 'B' && (sky[y + dy[i]][x + dx[i]] == 'A' || sky[y + dy[i]][x + dx[i]] == 'a'))){
				return cnt;
			}
			if (sky[y + dy[i]][x + dx[i]] == 'X' || ((sky[y][x] == 'A' || sky[y][x] == 'B') && (sky[y+dy[i]][x+dx[i]] == 'Z' || sky[y+dy[i]][x+dx[i]] == 'z'))){
				sky[y + dy[i]][x + dx[i]] = sky[y][x];
				enqueue(x + dx[i], y + dy[i]);
			}
		}
		if (sky[y][x] >= 'A' && sky[y][x] <= 'Z' && sky[y][x] != 'L')
			sky[y][x] += ('a'-'A');
	}
	return cnt;
}

int main()
{
	int i, j, ax, ay, bx, by, temp_test=0;
	scanf("%d %d", &r, &c);
	for (i = 1; i <= r; i++){
		scanf("%s", &sky[i][1]);
		sky[i][0] = 'I';
		sky[i][c + 1] = 'I';
		for (j = 1; j <= c; j++){
			if (sky[i][j] == 'L'){
				if (temp_test == 0){
					ax = j;
					ay = i;
					temp_test = 1;
				}
				else{
					bx = j;
					by = i;
				}
			}
		}
	}
	for (i = 0; i <= c + 1; i++){
		sky[0][i] = 'I';
		sky[r + 1][i] = 'I';
	}

	bfs_setting(ax, ay, 'a');
	bfs_setting(bx, by, 'b');
	for (i = 1; i <= r; i++){
		for (j = 1; j <= c; j++){
			if (sky[i][j] == '.'){
				sky[i][j] = 'z';
				bfs_setting(j, i, 'z');
			}
		}
	}
	head = 0;
	tail = 0;

	for (i = 1; i <= r; i++){
		for (j = 1; j <= c; j++){
			if (sky[i][j] == 'Z'){
				enqueue(j, i);
			}
		}
	}
	for (i = 1; i <= r; i++){
		for (j = 1; j <= c; j++){
			if (sky[i][j] == 'A' || sky[i][j] == 'B' || sky[i][j] == 'L'){
				enqueue(j, i);
			}
		}
	}
	// finish setting

	printf ("%d", bfs());

	return 0;
}
/*
input
23 20
.X.X.XLX.X.X.X.X.X.X
X.X.X.X.X.X.X.X.X.X.
.X.X.X.X.X.X.X.X.X.X
X.X.X.X.X.X.X.X.X.X.
.X.X.X.X.X.X.X.X.X.X
X.X.X.X.X.X.X.X.X.X.
.X.X.X.X.X.X.X.X.X.X
X.X.X.X.X.X.X.X.X.X.
XXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXX
.XXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXX
.XX.XXX.XX.XXX.XXX.X
XXXXXXXXXXXXXXXXXXX.
XXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXX.
XXXXXXXXXXXXXXXXXXXX
X.X.X.X.X.X.X.X.X.XX
.X.X.X.X.X.XLX.X.X.X

output
2
*/