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
int fir[5000010], to[5000010], val[5000010], nex[5000010], n, m, u, v, w, cnt, k;
int mustpassPoint[1000010];
const int inf = 2147483647;
long long disbegin[1000010], disend[1000010];
bool book[1000010];
void add(int a, int b, int c) //链式前向星
{
    to[++cnt] = b;
    val[cnt] = c;
    nex[cnt] = fir[a];
    fir[a] = cnt;
}
int main()
{
    std::ios::sync_with_stdio(false); //有了这两句之后就不能使用printf，scanf
    std::cin.tie(0);
    cin >> n >> m >> k;          //读入
    for (int i = 1; i <= m; i++) //读图
    {
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> mustpassPoint[i];
    }

    for (int i = 1; i <= n; i++) //初始化
    {
        disbegin[i] = inf;
    }
    disbegin[1] = 0;
    q.push(make_pair(0, 1)); //根节点入队
    while (!q.empty())       // Dijkstra算法+堆优化 的模板
    {
        int x = q.top().second;
        q.pop();
        if (book[x])
            continue;
        book[x] = 1;
        for (int i = fir[x]; i; i = nex[i])
        {
            if (disbegin[to[i]] > disbegin[x] + val[i])
            {
                disbegin[to[i]] = disbegin[x] + val[i];
                q.push(make_pair(disbegin[to[i]], to[i]));
            }
        }
    }
    // cout<<disbegin[4]<<endl;
    memset(book, 0, sizeof(book));
    for (int i = 1; i <= n; i++) //初始化
    {
        disend[i] = inf;
    }
    disend[n] = 0;
    q.push(make_pair(0, n)); //根节点入队
    while (!q.empty())       // Dijkstra算法+堆优化 的模板
    {
        int x = q.top().second;
        q.pop();
        if (book[x])
            continue;
        book[x] = 1;
        for (int i = fir[x]; i; i = nex[i])
        {
            if (disend[to[i]] > disend[x] + val[i])
            {
                disend[to[i]] = disend[x] + val[i];
                q.push(make_pair(disend[to[i]], to[i]));
            }
        }
    }
    // cout<<disend[4]<<endl;
    // cout<<mustpassPoint[1]<<endl;
    long long int ans = INT64_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (disbegin[mustpassPoint[i]] < inf && disend[mustpassPoint[i]] < inf)
        {
            ans = min(ans, disbegin[mustpassPoint[i]] + disend[mustpassPoint[i]]);
        }
    }
    cout << ans << endl;
    return 0;
}