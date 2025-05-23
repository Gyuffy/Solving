#include <iostream>
using namespace std;

int N, M;
int cnt[20000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        cnt[num + 10000000]++;
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> num;
        cout << cnt[num + 10000000] << " ";
    }
    cout << "\n";

    return 0;
}
