#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
vector<long long> v;
vector<long long> sumTree;

void build(int node, int l, int r)
{
	if (l == r)
	{
		sumTree[node] = v[l];
		return;
	}

	int mid = (l + r) / 2;
	build(node * 2, l, mid);
	build(node * 2 + 1, mid + 1, r);

	sumTree[node] = sumTree[node * 2] + sumTree[node * 2 + 1];
}

void update(int node, int nodeLeft, int nodeRight, int queryIndex, long long value)
{
	if (queryIndex < nodeLeft || nodeRight < queryIndex)
	{
		return;
	}

	if (nodeLeft == nodeRight)
	{
		sumTree[node] = value;
		return;
	}

	int mid = (nodeLeft + nodeRight) / 2;

	update(node * 2, nodeLeft, mid, queryIndex, value);
	update(node * 2 + 1, mid + 1, nodeRight, queryIndex, value);

	sumTree[node] = sumTree[node * 2] + sumTree[node * 2 + 1];
}

long long querySum(int node, int nodeLeft, int nodeRight, int queryLeft, int queryRight)
{
	if (queryRight < nodeLeft || nodeRight < queryLeft)
	{
		return 0;
	}

	if (queryLeft <= nodeLeft && nodeRight <= queryRight)
	{
		return sumTree[node];
	}

	int mid = (nodeLeft + nodeRight) / 2;
	long long leftSum = querySum(node * 2, nodeLeft, mid, queryLeft, queryRight);
	long long rightSum = querySum(node * 2 + 1, mid + 1, nodeRight, queryLeft, queryRight);

	return leftSum + rightSum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;

	v.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	sumTree.assign(4 * N, 0);
	build(1, 0, N - 1);

	for (int i = 0; i < M + K; i++)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		
		if (a == 1)
		{
			update(1, 0, N - 1, b - 1, c);
		}
		else if (a == 2)
		{
			cout << querySum(1, 0, N - 1, b - 1, c - 1) << "\n";
		}
	}

	return 0;
}