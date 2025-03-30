#include <stdio.h>
#include <stdlib.h>

int dwarfs[9];

int static compare(const void* first, const void* second)
{
	int num1 = *(int*)first;
	int num2 = *(int*)second;

	if (num1 < num2)
		return -1;

	if (num1 > num2)
		return 1;

	return 0;
}

int main()
{
	int sum = 0;

	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &dwarfs[i]);
		sum += dwarfs[i];
	}

	qsort(dwarfs, 9, sizeof(int), compare);

	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - (dwarfs[i] + dwarfs[j]) == 100)
			{
				for (int k = 0; k < 9; k++)
				{
					if (k == i || k == j) continue;
					printf("%d\n", dwarfs[k]);
				}
				return 0;
			}
		}
	}

	return 0;
}