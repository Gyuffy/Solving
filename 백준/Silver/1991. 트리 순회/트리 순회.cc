#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
char root, leftChild, rightChild;
vector<char> tree[27];
int visited[27];

void init()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> root >> leftChild >> rightChild;
		tree[root - 'A'].push_back(leftChild);
		tree[root - 'A'].push_back(rightChild);
	}
}

void preorder(int lev)
{
	cout << (char)(lev + 'A');
	visited[lev] = 1;
	if (lev == N)
	{
		return;
	}

	for (int i = 0; i < tree[lev].size(); i++)
	{
		int next = tree[lev][i] - 'A';
		if (next == '.' - 'A')
			continue;
		if (visited[next] == 1)
			continue;
		visited[next] = 1;
		//cout << tree[lev][i];
		preorder(next);
		visited[next] = 0;
	}
}

void inorder(int lev)
{
	visited[lev] = 1;
	if (lev == N)
	{
		return;
	}

	// 왼쪽 서브트리 먼저 방문
	if (tree[lev].size() > 0) 
	{
		int left = tree[lev][0] - 'A';  // 왼쪽 자식 노드
		if (visited[left] == 0 && left != '.' - 'A') 
		{
			inorder(left);  // 왼쪽 서브트리 방문
		}
	}
	
	cout << (char)(lev + 'A');

	if (tree[lev].size() > 1) 
	{
		int right = tree[lev][1] - 'A';  // 오른쪽 자식 노드
		if (visited[right] == 0 && right != '.' - 'A') 
		{
			inorder(right);  // 오른쪽 서브트리 방문
		}
	}
}

void postorder(int lev)
{
	visited[lev] = 1;
	if (lev == N)
	{
		return;
	}

	for (int i = 0; i < tree[lev].size(); i++)
	{
		int next = tree[lev][i] - 'A';
		if (next == '.' - 'A')
			continue;
		if (visited[next] == 1)
			continue;
		visited[next] = 1;
		postorder(next);
		visited[next] = 0;
	}
	cout << (char)(lev + 'A');
}

int main()
{
	// freopen("sample_input.txt", "r", stdin);
	init();
	preorder(0);
	cout << "\n";
	memset(visited, 0, sizeof(visited));

	inorder(0);
	cout << "\n";
	memset(visited, 0, sizeof(visited));

	postorder(0);

	return 0;
}