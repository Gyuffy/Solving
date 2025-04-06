#include <stdio.h>

int isContain(int n)
{
    while (n != 0)
    {
        if (n % 10 == 7)
        {
            return 1;
        }
        n /= 10;
    }
    return 0;
}

int main()
{
    int num;
    scanf("%d", &num);
    if (isContain(num) && !(num % 7))
    {
        printf("3\n");
    }
    else if (isContain(num))
    {
        printf("2\n");
    }
    else if (!(num % 7))
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }
    return 0;
}