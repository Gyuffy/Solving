#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char str[9];
	scanf("%s", str);
	
	int a, b, c;
	int cnt = 0;

	sscanf(str, "%d:%d:%d", &a, &b, &c);

	if (a >= 1 && a <= 12 && b >= 0 && b <= 59 && c >= 0 && c <= 59) cnt++;
	if (a >= 1 && a <= 12 && b >= 0 && b <= 59 && c >= 0 && c <= 59) cnt++;
	if (a >= 0 && a <= 59 && b >= 1 && b <= 12 && c >= 0 && c <= 59) cnt++;
	if (a >= 0 && a <= 59 && b >= 0 && b <= 59 && c >= 1 && c <= 12) cnt++;
	if (a >= 0 && a <= 59 && b >= 0 && b <= 59 && c >= 1 && c <= 12) cnt++;
	if (a >= 0 && a <= 59 && b >= 1 && b <= 12 && c >= 0 && c <= 59) cnt++;

	printf("%d\n", cnt);
	return 0;
}