#include <algorithm>
using namespace std;

int n, m, temp;

struct Member
{
    int id;
    int ability;
    int league;
}members[39990];

bool cmpMember(Member a, Member b)
{
    if (a.ability == b.ability)
        return a.id < b.id;
    return a.ability > b.ability;
}

void swapMember(int a, int b)
{
    Member A, B;

    A = members[a];
    B = members[b];

    members[a] = B;
    members[b] = A;
}

void init(int N, int L, int mAbility[])
{
    // 입력부
    n = N;
    m = L;
    temp = n / m;

    int leag = 0;
    for (int i = 0; i < n; i++)
    {
        if (i != 0 && i % temp == 0)
            leag += 1;
        members[i].id = i;
        members[i].league = leag;
        members[i].ability = mAbility[i];
    }

    // Sort
    for (int i = 0; i < n; i++)
    {
        if (i % temp == 0)
            sort(members + i, members + (i + temp), cmpMember);
    }
}

int move()
{
    int sum = 0;

    for (int i = 1; i < n; i++)
    {
        if (i % temp == 0)
        {
            swapMember(i - 1, i);
            sum += members[i].id + members[i - 1].id;
        }
    }

    // Sort
    for (int i = 0; i < n; i++)
    {
        if (i % temp == 0)
            sort(members + i, members + (i + temp), cmpMember);
    }

    return sum;
}

int trade()
{
    int sum = 0;
    int mid = temp / 2;

    for (int i = 0; i < n; i++)
    {
        
    }

    return 0;
}