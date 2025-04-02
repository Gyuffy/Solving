#include <stdio.h>

int main()
{
	char number[10];
	int ans;

	scanf("%s", number);

	if (number[0] == '0' && number[1] == 'x')
	{
		sscanf(number, "%x", &ans);
		printf("%d", ans);
	}
	else if (number[0] == '0')
	{
		sscanf(number, "%o", &ans);
		printf("%d", ans);
	}
	else
	{
		sscanf(number, "%d", &ans);
		printf("%d", ans);
	}

	return 0;
}