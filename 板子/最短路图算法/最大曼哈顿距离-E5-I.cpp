#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int main()
{
	int t, n, m, a[5], i, j, k;
	long long val[32], x, ans;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		for (i = 0; i < (1 << m); i++)
			val[i] = -1e18;
		for (i = 1; i <= n; i++)
		{
			for (j = 0; j < m; j++)
				scanf("%d", &a[j]);
			for (j = 0; j < (1 << m); j++)
			{
				x = 0;
				for (k = 0; k < m; k++)
				{
					if (j & (1 << k))
						x += a[k];
					else
						x -= a[k];
				}
				val[j] = max(val[j], x);
			}
		}
		ans = -1e18;
		for (i = 0; i < (1 << m); i++)
			ans = max(ans, val[i] + val[i ^ ((1 << m) - 1)]);
		printf("%lld\n", ans);
	}
	
	return 0;
}
