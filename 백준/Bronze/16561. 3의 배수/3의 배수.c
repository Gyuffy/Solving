#include <stdio.h>

int main()
{
	int n;
	int cnt = 0;
	scanf("%d", &n);

	n /= 3;

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n - i; j++)
		{
			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}
