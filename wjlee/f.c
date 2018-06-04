#include <stdio.h>

int x_2[35], k_2[35], result_2[70];

int main()
{
	int i, j, cnt=0;
	unsigned long long x, k, result=0, x_original;
	
	scanf("%llu %llu", &x, &k);
	x_original = x;

	for (i = 0; i < 32; i++){
		x_2[i] = x % 2;
		k_2[i] = k % 2;
		result_2[i] = x_2[i];
		x /= 2;
		k /= 2;
		if (x == 0 && k == 0){
			break;
		}
	}
	/*for (i=31; i>=0; i--){
		printf ("%d", x_2[i]);
	}
	printf ("\n");
	for (i=31; i>=0; i--){
		printf ("%d", k_2[i]);
	}
	printf ("\n");*/

	for (i = 0; i < 64; i++){
		if (result_2[i] == 0) result_2[i] = k_2[cnt++];
		if (cnt > 31)
			break;
	}
	
	/*for (i=63; i>=0; i--){
		printf ("%d", result_2[i]);
	}
	printf ("\n");*/

	for (i = 63; i >=0; i--){
		result += result_2[i];
		result *= 2;
	}
	result /= 2;

	printf("%llu", result-x_original);

	return 0;
}