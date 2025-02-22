#include <iostream>

using namespace std;

int roller[1000][1000] = { 0 };
int r = 0, c = 0;

int move_x[4] = {0, 0, -1, 1 };
int move_y[4] = {-1, 1, 0, 0 };

int main()
{
	cin >> r >> c;
	
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> roller[i][j];
		}
	}

	int x_pos = 0;
	int y_pos = 0;
	int d = 0;
	string route;
	bool beforeR = false;
	bool beforeD = false;
	int even_flg = false;

	// R이 홀수인 경우
	if (r % 2 == 1) {
		for (int i = 0; i < r; ++i) {
			if (i % 2 == 0) {
				route += string(c - 1, 'R');
			}
			else {
				route += string(c - 1, 'L');
			}
			if (i != r - 1) route += "D";
		}
	}
	// C가 홀수인 경우
	else if (c % 2 == 1) {
		for (int i = 0; i < c; ++i) {
			if (i % 2 == 0) {
				route += string(r - 1, 'D');
			}
			else {
				route += string(r - 1, 'U');
			}
			if (i != c - 1) route += "R";
		}


	}

	if (r % 2 == 0 && c % 2 == 0)
	{
		while (true)
		{
			even_flg = true;
			break;

		}
	}

	bool isMinpt = false;
	bool evenFinal = false;

	if (even_flg)
	{
		int minScore = 1001;
		int min_x = 0;
		int min_y = 0;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (roller[i][j] < minScore && (i + j) % 2 == 1)
				{
					minScore = roller[i][j];
					min_x = j;
					min_y = i;
				}
			}
		}
		while (true)
		{
			if (y_pos >= min_y - 1 && y_pos % 2 == 0)
			{
				isMinpt = true;
				break;
			}

			d = beforeR ? 2 : 3;
			x_pos += move_x[d];
			y_pos += move_y[d];
			

			if (x_pos < 0 || y_pos < 0 || x_pos >= c || y_pos >= r)
			{
				x_pos -= move_x[d];
				y_pos -= move_y[d];
				d = 1;
				x_pos += move_x[d];
				y_pos += move_y[d];
				if (x_pos == c - 1 && y_pos == r - 1)
				{
					if (d == 0) route += "U";
					else if (d == 1) route += "D";
					else if (d == 2) route += "L";
					else route += "R";
					break;
				}
				else
				{
					route += "D";
					beforeR = !beforeR;
					// 최소포인트가 있는 행
					if (y_pos >= min_y - 1 && y_pos % 2 == 0)
					{
						isMinpt = true;
						break;
					}
				}
			}
			else
			{
				if (d == 0) route += "U";
				else if (d == 1) route += "D";
				else if (d == 2) route += "L";
				else route += "R";
			}
		}


		if (isMinpt)
		{
			int orderD[4] = { 1, 3, 0, 3 }; // DRUR
			int order = -1;

			while (true)
			{
				order++;
				d = orderD[order % 4];

				x_pos += move_x[d];
				y_pos += move_y[d];
				if (x_pos == c - 1 && y_pos == r - 1)
				{
					if (d == 0) route += "U";
					else if (d == 1) route += "D";
					else if (d == 2) route += "L";
					else route += "R";
					break;
				}
				if (x_pos < 0 || y_pos < 0 || x_pos >= c || y_pos >= r)
				{
					x_pos -= move_x[d];
					y_pos -= move_y[d];
					d = 1;
					x_pos += move_x[d];
					y_pos += move_y[d];
					if (x_pos == c - 1 && y_pos == r - 1)
					{
						if (d == 0) route += "U";
						else if (d == 1) route += "D";
						else if (d == 2) route += "L";
						else route += "R";
						break;
					}
					else
					{
						route += "D";
						evenFinal = true;
						beforeR = true;
						break;
					}
				}
				if (x_pos == min_x && y_pos == min_y)
				{
					x_pos -= move_x[d];
					y_pos -= move_y[d];
					if (d == 0) order = 0;
					else order = 2;
					continue;
				}
				else
				{
					if (d == 0) route += "U";
					else if (d == 1) route += "D";
					else if (d == 2) route += "L";
					else route += "R";
				}

			}
		}
		if (evenFinal)
		{
			while (true)
			{
				d = beforeR ? 2 : 3;
				x_pos += move_x[d];
				y_pos += move_y[d];
				if (x_pos == c - 1 && y_pos == r - 1)
				{
					if (d == 0) route += "U";
					else if (d == 1) route += "D";
					else if (d == 2) route += "L";
					else route += "R";
					break;
				}
				if (x_pos < 0 || y_pos < 0 || x_pos >= c || y_pos >= r)
				{
					x_pos -= move_x[d];
					y_pos -= move_y[d];
					d = 1;
					x_pos += move_x[d];
					y_pos += move_y[d];
					if (x_pos == c - 1 && y_pos == r - 1)
					{
						if (d == 0) route += "U";
						else if (d == 1) route += "D";
						else if (d == 2) route += "L";
						else route += "R";
						break;
					}
					else
					{
						route += "D";
						beforeR = !beforeR;
					}
				}
				else
				{
					if (d == 0) route += "U";
					else if (d == 1) route += "D";
					else if (d == 2) route += "L";
					else route += "R";
				}
			}
		}
	}

	cout << route;
}