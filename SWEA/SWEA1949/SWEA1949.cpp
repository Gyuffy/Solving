// SWEA 1949번 [모의 SW 역량테스트] 등산로 조성
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct Peak
{
	int y, x;
}peaks[5];

int N, K, cons, max_len, max_val, num_of_peaks;
int MAP[8][8];
//int path[21];
int visited[8][8];

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

void init()
{
	cons = 0;
	max_len = 0;
	max_val = 0;
	num_of_peaks = 0;
	/*for (int i = 0; i < 21; i++)
	{
		path[i] = -1;
	}*/
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			visited[i][j] = 0;
		}
	}
}

void input()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
			if (MAP[i][j] > max_val)
			{
				max_val = MAP[i][j];
				num_of_peaks = 0;
				peaks[num_of_peaks].y = i;
				peaks[num_of_peaks].x = j;
				num_of_peaks++;
			}
			else if (MAP[i][j] == max_val)
			{
				peaks[num_of_peaks].y = i;
				peaks[num_of_peaks].x = j;
				num_of_peaks++;
			}
		}
	}
}

void recur(int lev, int sy, int sx, int len)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = sy + dy[i];
		int nx = sx + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= N)
			continue;
		if (visited[ny][nx] == 1)
		{
			continue;
		}
		int diff = MAP[ny][nx] - MAP[sy][sx];
		if (diff >= 0 && cons == 1)
			continue;
		if (diff >= 0 && cons == 0)
		{
			if (diff >= K)
				continue;
			else
			{
				visited[ny][nx] = 1;
				//path[lev] = i;
				cons = 1;
				int val = MAP[ny][nx] - MAP[sy][sx] + 1;
				MAP[ny][nx] -= val;
				len++;
				recur(lev + 1, ny, nx, len);
				len--;
				MAP[ny][nx] += val;
				cons = 0;
				//path[lev] = -1;
				visited[ny][nx] = 0;
			}
		}
		else
		{
			visited[ny][nx] = 1;
			//path[lev] = i;
			len++;
			recur(lev + 1, ny, nx, len);
			len--;
			//path[lev] = -1;
			visited[ny][nx] = 0;
		}
	}

	// 종료 조건은 따로 주어지지 않고, 모든 방향의 순회가 끝나면 종료
	if (len > max_len)
	{
		max_len = len;
		/*for (int i = 0; i < lev; i++)
		{
			cout << path[i] << " ";
		}
		cout << "\n" << "-----------" << "\n\n";*/
	}
}

int main()
{
	// 입출력 설정
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	// 테스트 케이스 시작
	int T, test_case;
	cin >> T;

	for (test_case = 1; test_case <= T; test_case++)
	{
		init();
		input();
		for (int i = 0; i < num_of_peaks; i++)
		{
			visited[peaks[i].y][peaks[i].x] = 1;
			recur(0, peaks[i].y, peaks[i].x, 1);
			visited[peaks[i].y][peaks[i].x] = 0;
		}
		cout << "#" << test_case << " " << max_len << "\n";
	}

	return 0;
}