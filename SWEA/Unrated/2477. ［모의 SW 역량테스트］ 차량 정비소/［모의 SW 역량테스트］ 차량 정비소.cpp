#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Customer
{
	int num;		// 고객 번호
	int rec = -1;	// 접수 창구의 번호
	int rep = -1;	// 정비 창구의 번호
	int enter;		// 입장 시간
	int t;			// 웨이팅 상태
};

int N, M, K, A, B;
int reception[10];
int repair[10];
int sum, escape;

// 인원 체크
vector<Customer> chkRec[10];
vector<Customer> chkRep[10];

// 고객 도착 큐
queue<Customer> qArv;

// 고객 대기 큐
queue<Customer> qRec;
queue<Customer> qRep;

void init()
{
	sum = 0;
	escape = 0;
}

void input()
{
	int custNum = 1, enterTime;

	cin >> N >> M >> K >> A >> B;
	for (int i = 1; i <= N; i++)
	{
		cin >> reception[i];
	}
	for (int i = 1; i <= M; i++)
	{
		cin >> repair[i];
	}
	for (int i = 0; i < K; i++)
	{
		cin >> enterTime;
		qArv.push({ custNum, -1, -1, enterTime, 0 });
		custNum++;
	}
}

void solve()
{
	int t = 0;
	bool endLoop = false;
	while (true)
	{
		// 도착한 고객 확인
		if (!qArv.empty())
		{
			for (int i = 0; i < qArv.size(); i++)
			{
				Customer now = qArv.front();
				if (t >= now.enter)
				{
					qArv.pop();
					qRec.push(now);
				}
				else if (now.enter > t)
				{
					break;
				}
			}
		}

		// 접수 대기열 -> 접수 창구
		if (!qRec.empty())
		{
			int lev = qRec.size();
			for (int i = 0; i < lev; i++)
			{
				bool flag = false;
				Customer now = qRec.front();
				for (int j = 1; j <= N; j++)
				{
					if (chkRec[j].size() == 0)
					{
						now.rec = j;
						now.t = reception[j];
						chkRec[j].push_back(now);
						qRec.pop();
						break;
					}
					else if (j == N)
					{
						flag = true;
					}
				}

				// 한 번 먼저 살펴봤는데 모든 창구가 찼으면 순회 안함
				if (flag)
				{
					break;
				}
			}
		}

		// 접수 -> 수리 대기열
		for (int i = 1; i <= N; i++)
		{
			if (chkRec[i].size() != 0)
			{
				chkRec[i][0].t--;
				Customer now = chkRec[i][0];
				int remain = now.t;

				if (remain == 0)
				{
					chkRec[i].pop_back();
					qRep.push(now);
					// 접수가 끝나면 접수 대기열에 있는 고객을 불러옴
					if (!qRec.empty())
					{
						Customer addMember = qRec.front();
						addMember.rec = i;
						addMember.t = reception[i];
						chkRec[i].push_back(addMember);
						qRec.pop();
					}
				}
			}
		}

		// 수리 대기열 -> 수리 창구
		if (!qRep.empty())
		{
			int lev = qRep.size();
			for (int i = 0; i < lev; i++)
			{
				bool flag = false;
				Customer now = qRep.front();
				for (int j = 1; j <= M; j++)
				{
					if (chkRep[j].size() == 0)
					{
						now.rep = j;
						now.t = repair[j];
						chkRep[j].push_back(now);
						qRep.pop();
						break;
					}
					else if (j == M)
					{
						flag = true;
					}
				}
				if (flag)
					break;
			}
		}

		// 수리 창구 -> 설문 조사
		for (int i = 1; i <= M; i++)
		{
			if (chkRep[i].size() != 0)
			{
				chkRep[i][0].t--;
				Customer now = chkRep[i][0];
				int remain = now.t;

				if (remain == 0)
				{
					chkRep[i].pop_back();
					escape++;

					// 수리 창구의 자리가 비면 대기열의 고객을 호출
					if (!qRep.empty())
					{
						Customer addMember = qRep.front();
						addMember.rep = i;
						addMember.t = repair[i];
						chkRep[i].push_back(addMember);
						qRep.pop();
					}

					// 지갑을 분실한 인원의 정보와 일치하면 해당 고객번호를 더해준다.
					if (now.rec == A && now.rep == B)
					{
						sum += now.num;
					}

					if (escape == K)
					{
						endLoop = true;
					}
				}
			}
		}

		// 종료
		if (endLoop)
			break;

		// 시간 증가
		t++;
	}

	sum = sum == 0 ? -1 : sum;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	// freopen("sample_input.txt", "r", stdin);
	int T, tc;
	cin >> T;
	for (tc = 1; tc <= T; tc++)
	{
		init();
		input();
		solve();
		cout << "#" << tc << " " << sum << "\n";
	}

	return 0;
}