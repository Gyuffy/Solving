#include <stdio.h>

int main()
{
	int a, b, n, w;
	int A, B;
	int A_res, B_res;
	int cnt = 0;
	scanf("%d %d %d %d", &a, &b, &n, &w);
	
	for (int i = 1; i < n; i++)
	{
		A = i;
		B = n - i;

		if((A * a) + (B * b) == w)
		{
			A_res = A;
			B_res = B;
			cnt++;
		}
	}


	if(cnt != 1)
	{
		printf("-1\n");
		return 0;
	}


	printf("%d %d\n", A_res, B_res);


	return 0;
}
