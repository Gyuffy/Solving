#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a, b, c, N;
	int a_, b_, c_;

	scanf("%d %d %d %d", &a, &b, &c, &N);

	for (int i = 0; i <= N; i++)
	{
		a_ = a * i;
		for (int j = 0; j <= N; j++)
		{
			b_ = b * j;
			for (int k = 0; k <= N; k++)
			{
				c_ = c * k;
				if (a_ + b_ + c_ == N)
				{
					printf("1\n");
					return 0;
				}
			}
		}
	}

	printf("0\n");

	return 0;
}