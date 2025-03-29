#include <stdio.h>

int main()
{
	int N;
	long long pw[10];
	
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int is_no = 0;

		scanf("%lld", &pw[i]);

		for (int j = 2; j <= 1000000; j++)
   		{
        	if (pw[i] % j == 0)
			{
				printf("NO\n");
				is_no = 1;
				break;
			}
    	}

		if(is_no == 1)
		{
			continue;
		}

		printf("YES\n");
	}


	return 0;
}
