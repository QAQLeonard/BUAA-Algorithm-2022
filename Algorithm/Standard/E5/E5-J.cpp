#include <stdio.h>

#define maxn 205
#define min(a, b) (a < b ? a : b)

typedef long long ll;

int main()
{
	int a[maxn][maxn], t, n, m, q, i, j, x1, y1, x2, y2;
	ll f[maxn][maxn], g[maxn][maxn], pre[maxn][maxn], suf[maxn][maxn], ans;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d", &n, &m, &q);
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				scanf("%d", &a[i][j]);
				f[i][j] = g[i][j] = 1e18;
			}
		}
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				if (i == 1 && j == 1) f[i][j] = 0;
				if (i - 1 > 0) f[i][j] = min(f[i][j], f[i - 1][j] + a[i][j]);
				if (j - 1 > 0) f[i][j] = min(f[i][j], f[i][j - 1] + a[i][j]);
			}
		}
		for (i = n; i; i--)
		{
			for (j = m; j; j--)
			{
				if (i == n && j == m) g[i][j] = 0;
				if (i + 1 <= n) g[i][j] = min(g[i][j], g[i + 1][j] + a[i][j]);
				if (j + 1 <= m) g[i][j] = min(g[i][j], g[i][j + 1] + a[i][j]);
			}
		}
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				if (j == 1)
					pre[i][j] = f[i][j] + g[i][j] - a[i][j];
				else
					pre[i][j] = min(pre[i][j - 1], f[i][j] + g[i][j] - a[i][j]);
			}
			for (j = m; j; j--)
			{
				if (j == m)
					suf[i][j] = f[i][j] + g[i][j] - a[i][j];
				else
					suf[i][j] = min(suf[i][j + 1], f[i][j] + g[i][j] - a[i][j]);
			}
		}
		while (q--)
		{
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			if (x2 - x1 + 1 == n || y2 - y1 + 1 == m || (x1 == 1 && y1 == 1) || (x2 == n && y2 == m))
			{
				puts("-1");
				continue;
			}
			ans = 1e18;
			if (x2 < n && y1 > 1) ans = min(ans, pre[x2 + 1][y1 - 1]);
			if (x1 > 1 && y2 < m) ans = min(ans, suf[x1 - 1][y2 + 1]);
			printf("%lld\n", ans);
		}
	}

	return 0;
}
