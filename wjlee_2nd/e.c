#include <stdio.h>
 
int paper[130][130];
int blue, white;
 
int check(int start_x, int start_y, int size)
{
    int a, b, c, d;
    if (size == 1){
        if (paper[start_y][start_x] == 0) // white
            return 1; // white
        else
            return -1; // blue
    }
    else{
        a = check(start_x, start_y, size / 2);
        b = check(start_x + size/2, start_y, size / 2);
        c = check(start_x, start_y + size / 2, size / 2);
        d = check(start_x + size / 2, start_y + size / 2, size / 2);
        if (a + b + c + d == 4){
            return 1;
        }
        else if (a + b + c + d == -4){
            return -1;
        }
        else{
            if (a == 1) white++;
            else if (a == -1) blue++;
            if (b == 1) white++;
            else if (b == -1) blue++;
            if (c == 1) white++;
            else if (c == -1) blue++;
            if (d == 1) white++;
            else if (d == -1) blue++;
 
            return 0;
        }
    }
}
 
int main()
{
    int i, j;
    int n, temp;
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            scanf("%d", &paper[i][j]);
        }
    }
    temp = check(0, 0, n);
    if (temp == 1) white++;
    else if (temp == -1) blue++;
    printf("%d\n%d\n", white, blue);
    return 0;
}
