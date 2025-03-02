#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

struct Task
{
	int t;
	vector<int> pre;
}tasks[50];

int N, ans;
bool nothing;
bool done[50];

void init()
{
	ans = 21e8;
	nothing = false;

	for (int i = 0; i < 50; i++)
	{
		tasks[i].pre.clear();
		done[i] = 0;
	}
}

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int M;
		cin >> tasks[i].t >> M;
		for (int j = 0; j < M; j++)
		{
			int priorNum;
			cin >> priorNum;
			tasks[i].pre.push_back(priorNum - 1);
		}
	}
}

struct TempAdd
{
	int clr;
	int ct;
};

TempAdd chkAdd(int addTask)
{
	int ct = 0;
	for (int i = 0; i < N; i++)
	{
		// 이미 완수된 업무 고려 x
		if (done[i])
			continue;

		Task cur = tasks[i];

		bool skip = false;
		int maxTime = 0;
		for (int j = 0; j < cur.pre.size(); j++)
		{
			if (!done[cur.pre[j]])
			{
				skip = true;
				break;
			}
			maxTime = maxTime < tasks[cur.pre[j]].t ? tasks[cur.pre[j]].t : maxTime;
		}
		if (skip)
			continue;

		cur.t = cur.t + maxTime;
		addTask++;
		done[i] = true;
		ct = ct < cur.t ? cur.t : ct;
	}
	return { addTask, ct };
}

void simulate()
{
	int sumTime = 0;
	int clearTask = 0;
	bool clearFlag = false;

	while (true)
	{
		// 종료 조건
		if (clearFlag)
			break;

		int cycleTime = 0;
		for (int i = 0; i < N; i++)
		{
			// 완수된 업무는 고려하지 않음
			if (done[i])
				continue;

			Task cur = tasks[i];

			// 선행 업무가 필요하다면 제외
			bool skip = false;
			int maxTime = 0;
			for (int j = 0; j < cur.pre.size(); j++)
			{
				if (!done[cur.pre[j]])
				{
					skip = true;
					// 한 사이클을 모두 순회했지만,
					// 어떤 업무도 처리할 수 없었던 경우
					if (i == N - 1 && cycleTime == 0)
					{
						ans = -1;
						nothing = true;
						return;
					}
					break;
				}
				maxTime = maxTime < tasks[cur.pre[j]].t ? tasks[cur.pre[j]].t : maxTime;
			}
			if (skip)
				continue;

			cur.t = cur.t + maxTime;

			// 한바퀴 업무 처리
			cycleTime = cycleTime < cur.t ? cur.t : cycleTime;
			done[i] = true;
			clearTask++;

			// 더 처리할 연속적인 업무가 있는가 확인
			TempAdd temp = chkAdd(0);
			clearTask += temp.clr;
			int tmpTime = temp.ct;

			cycleTime = cycleTime < tmpTime ? tmpTime : cycleTime;

			// 종료 예약
			if (clearTask == N)
				clearFlag = true;
		}
		// 한 사이클마다 걸린 시간 합계
		sumTime += cycleTime;
	}

	ans = ans < sumTime ? ans : sumTime;

	// 처리 목록 초기화
	for (int j = 0; j < N; j++)
	{
		done[j] = false;
	}
}

void solve()
{
	// 도와줄 업무 선정
	for (int i = 0; i < N; i++)
	{
		int originTime = tasks[i].t;
		tasks[i].t = originTime / 2;

		simulate();

		if (nothing)
			return;

		tasks[i].t = originTime;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	freopen("sample_input.txt", "r", stdin);

	int T, test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++)
	{
		init();
		input();
		solve();
		cout << "#" << test_case << " " << ans << "\n";
	}

	return 0;
}