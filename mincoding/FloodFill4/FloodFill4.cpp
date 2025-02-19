// Flood Fill의 탑 4번 나이트 라이더
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

struct Point
{
    int y, x;
}pt, tg;

int H, W;
int MAP[101][101];
int visited[101][101];
int dist[101][101];
int dy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

void bfs(Point st)
{
    queue<Point> q;
    q.push(st);
    visited[st.y][st.x] = 1;

    while (!q.empty())
    {
        Point now = q.front();
        q.pop();

        if (now.y == tg.y && now.x == tg.x)
        {
            cout << dist[now.y][now.x] << "\n";
            return;
        }

        for (int i = 0; i < 8; i++)
        {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (visited[ny][nx])
                continue;
            if (ny < 0 || nx < 0 || ny > H || nx > W)
                continue;
            
            visited[ny][nx] = 1;
            dist[ny][nx] = dist[now.y][now.x] + 1;
            q.push({ ny, nx });

        }

    }

}

int main()
{
    //freopen("sample_input.txt", "r", stdin);
    cin >> H >> W;
    cin >> pt.y >> pt.x >> tg.y >> tg.x;

    bfs({ pt.y, pt.x });

    return 0;
}