#include <stdio.h>
 
int main()
{
    int i, j, n, n_digit, multiple_2 = 1, sum=0, n_temp;
    int n_2[35] = { 0, };
    int num_of_1[35] = { 0, };
    scanf("%d", &n);
    n_temp = n;
 
    for (i = 0; i < 32; i++){
        n_2[i] = n_temp % 2;
        n_temp /= 2;
        if (n_temp == 0){
            n_digit = i;
            break;
        }
    }
 
    num_of_1[0] = 1;
    multiple_2 *= 2;
    for (i = 1; i < n_digit; i++){
        num_of_1[i] = num_of_1[i - 1] * 2 + multiple_2;
        multiple_2 *= 2;
    }
 
    for (i = n_digit; i >= 0; i--){
        if (n_2[i] == 1){
            if (i == 0){
                sum++;
                break;
            }
            sum += num_of_1[i-1];
            sum += (n - multiple_2 + 1);
            n -= multiple_2;
        }
        multiple_2 /= 2;
    }
    printf("%d", sum);
 
    return 0;
}
