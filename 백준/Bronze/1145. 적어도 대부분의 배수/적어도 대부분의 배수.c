#include <stdio.h>

int main()
{
	int numbers[5];
	
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &numbers[i]);
	}

	int cnt = 0;
	int multiple = 3;
	
	while(multiple++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (multiple % numbers[i] == 0)
			{
				cnt++;
			}
		}

		if (cnt >= 3)
		{
			printf("%d\n", multiple);
			break;
		}

		cnt = 0;
	}

	return 0;
}
