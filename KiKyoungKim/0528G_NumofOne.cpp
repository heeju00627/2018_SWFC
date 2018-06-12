#include <iostream>
using namespace std;

long long int pow2[32] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};
long long int pow2num[32] = { 1, 2, 5, 13, 33, 81, 193, 449, 1025, 2305, 5121, 11265, 24577, 53249, 114689, 245761, 524289, 1114113, 2359297, 4980737, 10485761, 22020097, 46137345, 96468993, 201326593, 419430401, 872415233, 1811939329, 3758096385, 7784628225, 16106127361, 33285996545 };
// number of one for power of 2 is
// 2^(n-1) * n-1 +1 
// 1 : 0 * 0 + 1
// 2 : 1 * 1 + 1
// 4 : 2 * 2 + 1
// 8 : 4 * 3 + 1
// and so on...

// then N can divided into power of 2 and remaining.
// ex) 28 > 16 + 12 
//				  8 + 4
// each remainings are also can be divied into... 
// and when it returns, there are three part.
// for 28, 
// 1. power of 2. (16)
// 2. remaining. (12) > if remaining is not power of 2, call again.
//  2-1. power of 2. (8)
//  2-2. reamining. (4) > it is power of 2, returns from pow2num[2].
// at 2, it returns 12's num that is pow2num[3](8's num) + pow2num[2](4's num) AND 4
// at 1, it returns 28's num that is pow2num[4](16's num) + 12's num AND 12.


int N;
long long int sum;

long long int findsum(int n)
{
	for (int i = 30; i >= 0; i--)
	{
		if (n == pow2[i])
			return pow2num[i];
		else if (n > pow2[i])
		{
			return pow2num[i] + findsum(n - pow2[i]) + (n - pow2[i]);
		}
	}
}

int main(void)
{
	cin >> N;

	sum = findsum(N);
	cout << sum << endl;

	return 0;
}