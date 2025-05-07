#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge
{
    int y, x;
    int cost;
};

struct compare
{
    bool operator()(Edge a, Edge b)
    {
        return a.cost > b.cost;
    }
};

struct Point
{
    int y, x;
};

struct cmp_pt
{
    bool operator()(Point a, Point b)
    {
        if (a.y == b.y)
        {
            return a.x > b.x;
        }
        return a.y > b.y;
    }
};

int N;
int baby_size = 2, exp_stat = 0, hunt_time = 0;
int map_data[20][20];
int dist[20][20];
int target_dist = 21e8;
priority_queue<Point, vector<Point>, cmp_pt> target_q;
Point target_pos;
Point baby_pos;
int dy[] = { -1, 0, 0, 1 };
int dx[] = { 0, -1, 1, 0 };

void dijkstra(Point st)
{
    priority_queue<Edge, vector<Edge>, compare> pq;
    pq.push({ st.y, st.x, 0 });
    dist[st.y][st.x] = 0;

    while (!pq.empty())
    {
        Edge now = pq.top();
        pq.pop();

        if (dist[now.y][now.x] < now.cost)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (ny >= N || ny < 0 || nx >= N || nx < 0)
                continue;
            if (map_data[ny][nx] > baby_size)
                continue;

            int next_cost = now.cost + 1;
            if (next_cost > target_dist)
                continue;

            if (next_cost < dist[ny][nx])
            {
                dist[ny][nx] = next_cost;
                pq.push({ ny, nx, next_cost });

                if (map_data[ny][nx] != 0 && map_data[ny][nx] < baby_size)
                {
                    target_q.push({ ny, nx });
                    target_dist = next_cost;
                }
            }

        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map_data[i][j];
            if (map_data[i][j] == 9)
            {
                map_data[i][j] = 0;
                baby_pos = { i, j };
            }
        }
    }

    while (true)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                dist[i][j] = 21e8;
            }
        }
        while (!target_q.empty())
        {
            target_q.pop();
        }
        target_dist = 21e8;

        dijkstra(baby_pos);

        if (!target_q.empty())
        {
            target_pos = target_q.top();
            exp_stat++;
            if (baby_size == exp_stat)
            {
                baby_size++;
                exp_stat = 0;
            }
            map_data[target_pos.y][target_pos.x] = 0;
            hunt_time += dist[target_pos.y][target_pos.x];
            baby_pos = target_pos;
        }
        else
            break;
    }
    
    cout << hunt_time << "\n";


    return 0;
}