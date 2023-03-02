#include <iostream>
using namespace std;

#define inf 0x3f3f3f3f
int map[100 + 5][100 + 5];

void songchi(int n, int K)
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (k <= K && map[i][j] > map[i][k] + map[k][j])
                {
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }
}

void init(int n)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                map[i][j] = 0;
            else
                map[i][j] = inf;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, t, K, q, x, y;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> K;
        init(n);

        for (int i = 1; i <= m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            if (c < map[a][b])
            {
                map[a][b] = c;
                map[b][a] = c;
            }
        }
        songchi(n, K);

        cin >> q;
        while (q--)
        {
            cin >> x >> y;
            if (map[x][y] == inf)
                printf("QAQ\n");
            else
                printf("%d\n", map[x][y]);
        }
    }
    return 0;
}
