#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <queue> //头文件
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; //小根堆
int fir[500001], to[500001], val[500001], nex[500001], n, m, s, u, v, w, cnt, t;
const int inf = 2147483647;
long long dis[10001];
bool book[100001];
void add(int a, int b, int c) //链式前向星
{
    to[++cnt] = b;
    val[cnt] = c;
    nex[cnt] = fir[a];
    fir[a] = cnt;
}
int main()
{
    cin >> n >> m >> s >> t;     //读入
    for (int i = 1; i <= m; i++) //读图
    {
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    for (int i = 1; i <= n; i++) //初始化
    {
        dis[i] = inf;
    }
    dis[s] = 0;
    q.push(make_pair(0, s)); //根节点入队
    while (q.size())         // Dijkstra算法+堆优化 的模板
    {
        int x = q.top().second;
        q.pop();
        if (book[x])
            continue;
        book[x] = 1;
        for (int i = fir[x]; i; i = nex[i])
        {
            if (dis[to[i]] > dis[x] + val[i])
            {
                dis[to[i]] = dis[x] + val[i];
                q.push(make_pair(dis[to[i]], to[i]));
            }
        }
    }
    cout << dis[t] << " ";
    return 0;
}