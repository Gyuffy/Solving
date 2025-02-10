#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int T, test_case, N;
int table[16][16];
int choose_a[16];

void init()
{

}

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> table[i][j];
		}
	}
}

void cook(int row, int cnt)
{
	
	for (int i = 0; i < N; i++)
	{
		if (row == i)
		{
			continue;
		}
		choose_a[row] = i;
		
		
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++)
	{
		init();
		input();
		cook(0, 0);
	}
}