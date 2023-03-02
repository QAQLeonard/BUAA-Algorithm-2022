#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1e3 + 7;
int a[maxn][maxn], b[maxn][maxn];
int h[maxn][maxn];
int ans;
int n, m;

struct Node
{
    int x, y;
} mp1[maxn * maxn + 100], mp2[maxn * maxn + 100];

struct STK
{
    int l;
    int h, i;
} stk[maxn];

void solve(int j)
{
    int top = 0;
    stk[top].h = 0;
    stk[top].i = 0;
    mp2[0].x = INF;
    mp2[0].y = INF;
    h[n + 1][j] = 0;
    int flag = 0;
    for (int i = 0; i <= n + 1; i++)
        stk[i].l = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        if (mp1[b[i][j]].x == mp1[b[i - 1][j]].x + 1 && mp1[b[i][j]].y == mp1[b[i - 1][j]].y)
            flag = 1;
        else
            flag = 0;

        while (top && (stk[top].h > h[i][j] || !flag))
        {
            int s = (i - 1 - stk[top - 1].i) * stk[top].h;
            ans = max(ans, s);
            top--;
        }
        stk[++top].h = h[i][j];
        stk[top].i = i;
        if (!flag)
            stk[0].i = i - 1;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {

        scanf("%d%d", &n, &m);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &a[i][j]);
                mp1[a[i][j]].x = i;
                mp1[a[i][j]].y = j;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &b[i][j]);
                mp2[b[i][j]].x = i;
                mp2[b[i][j]].y = j;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (mp1[b[i][j]].x == mp1[b[i][j - 1]].x && mp1[b[i][j]].y == mp1[b[i][j - 1]].y + 1)
                {
                    h[i][j] = h[i][j - 1] + 1;
                }
                else
                    h[i][j] = 1;
            }
        }

        for (int i = 1; i <= m; i++)
        {
            solve(i);
        }

        printf("%d\n", ans);
    }

    return 0;
}
