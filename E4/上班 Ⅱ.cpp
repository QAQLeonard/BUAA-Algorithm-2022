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

priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> q; //小根堆
int fir[50000100], to[50000100], nex[50000100], n, m, s, u, v, w, cnt, t;
long long int val[50000100];
long long dis[50001000];
bool book[50001000];

void add(int a, int b, int c) //链式前向星
{
    to[cnt] = b;
    val[cnt] = c;
    nex[cnt] = fir[a];
    fir[a] = cnt;
    cnt++;
}
int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &t); //读入
    for (int i = 1; i <= m; i++)       //读图
    {
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    for (int i = 1; i <= n; i++) //初始化
    {
        dis[i] = INT64_MAX;
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
    printf("%lld", dis[t]);
    return 0;
}