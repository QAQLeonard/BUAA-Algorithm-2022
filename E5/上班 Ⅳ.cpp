#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1010, M = 100010;

int cases, n, m, S, F;
int h[N], e[M], w[M], ne[M], idx;
int dist[N][2], cnt[N][2];
bool st[N][2];

struct Node
{
    int id, type, dist;

    bool operator>(const Node &node) const
    {
        return dist > node.dist;
    }
};

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra()
{
    memset(st, 0, sizeof st);
    memset(dist, 0x3f, sizeof dist);
    dist[S][0] = 0, cnt[S][0] = 1;

    priority_queue<Node, vector<Node>, greater<Node>> q;
    q.push({S, 0, 0});

    while (q.size())
    {
        auto t = q.top();
        q.pop();

        int v = t.id, type = t.type;
        if (st[v][type])
            continue;
        st[v][type] = true;

        for (int i = h[v]; ~i; i = ne[i])
        {
            int j = e[i];

            if (dist[j][0] > dist[v][type] + w[i])
            {
                dist[j][1] = dist[j][0], cnt[j][1] = cnt[j][0];
                q.push({j, 1, dist[j][1]});
                dist[j][0] = dist[v][type] + w[i], cnt[j][0] = cnt[v][type];
                q.push({j, 0, dist[j][0]});
            }
            else if (dist[j][0] == dist[v][type] + w[i])
                cnt[j][0] += cnt[v][type];
            else if (dist[j][1] > dist[v][type] + w[i])
            {
                dist[j][1] = dist[v][type] + w[i], cnt[j][1] = cnt[v][type];
                q.push({j, 1, dist[j][1]});
            }
            else if (dist[j][1] == dist[v][type] + w[i])
                cnt[j][1] += cnt[v][type];
        }
    }

    int ret = cnt[F][0];
    // if (dist[F][0] + 1 == dist[F][1])
    //     ret += cnt[F][1];

    return ret;
}

int main()
{

    cin >> n >> m >> S >> F;

    memset(h, -1, sizeof h);
    idx = 0;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        add(a, b, 1);
        add(b, a, 1);
    }

    cout << dijkstra() << endl;

    return 0;
}
