#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static const long long INF = 4'000'000'000'000LL;

int N;
vector<long long> H;
vector<int> minIdxTree;

int build(int node, int l, int r)
{
	if (l == r)
	{
		return minIdxTree[node] = l;
	}

	int mid = (l + r) / 2;
	int leftIdx = build(node * 2, l, mid);
	int rightIdx = build(node * 2 + 1, mid + 1, r);

	return minIdxTree[node] = (H[leftIdx] < H[rightIdx]) ? leftIdx : rightIdx;
}

int queryMinIdx(int node, int l, int r, int ql, int qr)
{
	if (qr < l || r < ql)
	{
		return -1;
	}

	if (ql <= l && r <= qr)
	{
		return minIdxTree[node];
	}

	int mid = (l + r) / 2;
	int leftIdx = queryMinIdx(node * 2, l, mid, ql, qr);
	int rightIdx = queryMinIdx(node * 2 + 1, mid + 1, r, ql, qr);

	if (leftIdx == -1) return rightIdx;
	if (rightIdx == -1) return leftIdx;
	return (H[leftIdx] < H[rightIdx]) ? leftIdx : rightIdx;
}

long long solve(int l, int r)
{
	if (l > r)
	{
		return 0;
	}

	int minIdx = queryMinIdx(1, 0, N - 1, l, r);

	long long curArea = H[minIdx] * (r - l + 1);
	long long left = solve(l, minIdx - 1);
	long long right = solve(minIdx + 1, r);

	return max({ curArea, left, right });
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true)
	{
		cin >> N;
		if (N == 0)
		{
			break;
		}

		H.resize(N);
		for (int i = 0; i < N; i++)
		{
			cin >> H[i];
		}

		minIdxTree.assign(4 * N, 0);
		build(1, 0, N - 1);

		cout << solve(0, N - 1) << "\n";
	}


	return 0;
}