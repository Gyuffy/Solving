#include <iostream>

using namespace std;

int N, M;
int path[8];

<<<<<<< HEAD
void input()
{
    cin >> N >> M;
}

void func(int lev, int idx)
{
    // 종료 조건
    if(lev == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << path[i] << " ";
        }
        cout << "\n";
        
        return;
    }

    for (int i = idx; i <= N; i++)
    {
        path[lev] = i;
        func(lev + 1, idx + 1);
    }
    
=======
void func(int lev, int idx)
{
	if (lev == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << path[i] << " ";
		}
		cout << "\n";

		return;
	}

	for (int i = idx; i <= N; i++)
	{
		path[lev] = i;
		func(lev + 1, i);
	}

>>>>>>> 985b541246dd4bc51700f0fcae36b9e02669a82a
}

int main()
{
<<<<<<< HEAD
    input();
    func(0, 1);

    return 0;
=======
	cin >> N >> M;

	func(0, 1);


	return 0;
>>>>>>> 985b541246dd4bc51700f0fcae36b9e02669a82a
}