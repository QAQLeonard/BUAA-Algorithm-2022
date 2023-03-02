#include <stdio.h>
#include <string.h>

#define maxn 100086

char s[maxn], a[maxn];
int rk[maxn];

int main()
{
	int t, n, tmp, i, j, l, r, x;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", s + 1), n = strlen(s + 1);
		for (i = n; i; i--)
		{
			if (s[i] == s[i + 1])
				a[i] = a[i + 1];
			else
				a[i] = s[i + 1];
		}
		l = 1, r = n;
		for (i = 1; i <= n; i++)
		{
			if (s[i] > a[i])
				rk[i] = l++;
			else
				rk[i] = r--;
		}
		x = 0;
		for (i = 1; i <= n + 1; i++)
		{
			if (s[i] ^ s[i - 1])
			{
				if (x && rk[x] > rk[i - 1])
				{
					for (j = 1; j < i - x + 1 - j; j++)
					{
						tmp = rk[x - 1 + j];
						rk[x - 1 + j] = rk[x - 1 + i - x + 1 - j];
						rk[x - 1 + i - x + 1 - j] = tmp;
					}
				}
				x = i;
			}
		}
		for (i = 1; i <= n; i++)
			printf("%d ", rk[i]);
		puts("");
	}
	return 0;
}
