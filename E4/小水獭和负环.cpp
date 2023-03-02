#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 2005, M = 10005;

int n, m, st;
long long int dis[N], cnt[N];
int head[N], lnk[M], val[M], nxt[M], idx;
bool flag[N];
queue<int> q0;
priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> q; //小根堆
bool book[50001000];

void add(int u, int v, int w)
{
    lnk[idx] = v;
    val[idx] = w;
    nxt[idx] = head[u];
    head[u] = idx;
    idx++;
}

bool spfa()
{
    memset(flag, 0, sizeof flag);
    for (int i = 1; i <= n; i++)
    {
        flag[i] = true;
        q0.push(i);
        dis[i] = 0;
    }
    while (!q0.empty())
    {
        int u = q0.front();
        q0.pop();
        flag[u] = false;
        for (int i = head[u]; i != -1; i = nxt[i])
        {
            int v = lnk[i], w = val[i];
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n)
                    return true;
                if (!flag[v])
                {
                    q0.push(v);
                    flag[v] = true;
                }
            }
        }
    }
    return false;
}

int main()
{
    int t = 0;
    cin >> t;
    for (int time = 0; time < t; time++)
    {
        while (!q.empty())
            q.pop();
        while (!q0.empty())
            q0.pop();
        idx = 0;
        scanf("%d%d", &n, &m);
        memset(head, -1, sizeof head);
        memset(cnt, 0, sizeof cnt);
        memset(dis, 0x3f, sizeof dis);
        memset(book, 0, sizeof book);
        st = 1;
        int u, v, w;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w);
        }
        if (!spfa())
        {
            for (int i = 1; i <= n; i++) //初始化
            {
                dis[i] = INT64_MAX;
            }
            dis[1] = 0;
            q.push(make_pair(0, 1)); //根节点入队
            while (q.size())         // Dijkstra算法+堆优化 的模板
            {
                int x = q.top().second;
                q.pop();
                if (book[x])
                    continue;
                book[x] = 1;
                // cout << x << endl;
                
                for (int i = head[x]; i>=0; i = nxt[i])
                {
                    if (dis[lnk[i]] > dis[x] + val[i])
                    {
                        dis[lnk[i]] = dis[x] + val[i];
                        q.push(make_pair(dis[lnk[i]], lnk[i]));
                    }
                    // cout<<x<<" "<<lnk[i]<<" "<<dis[lnk[i]]<<endl;
                }
            }
            for (int i = 1; i <= n; i++)
            {
                if (dis[i] >= 0x3f3f3f3f)
                    printf("1000000000 ");
                else
                    printf("%lld ", dis[i]);
            }
            printf("\n");
        }
        else
            printf("boo how\n");
    }

    return 0;
}
