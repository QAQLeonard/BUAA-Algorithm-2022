#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int u, v, w;
    long long int sum = 0;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(n + 1, INT32_MAX));
    vector<int> dist(n + 1, INT32_MAX);
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        a[u][v] = min(a[u][v], w);
        a[v][u] = min(a[v][u], w);
    }
    dist[1] = 0;

    // 一共有 n 个点,就需要 遍历 n 次,每次寻找一个权值最小的点,记录其下标
    for (int i = 1; i <= n; i++)
    {
        int cur = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && (cur == -1 || dist[j] < dist[cur]))
            {
                cur = j;
            }
        }
        // // 这里需要提前终止
        // if (dist[cur] >= INT32_MAX)
        //     return 0;
        sum += dist[cur];
        vis[cur] = true;
        for (int k = 1; k <= n; k++)
        {
            // 只更新还没有找到的最小权值
            if (!vis[k])
                dist[k] = min(dist[k], a[cur][k]);
        }
    }
    cout << sum << endl;
    return 0;
}