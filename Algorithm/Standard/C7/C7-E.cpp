#include <stdio.h>
#define max(a, b) (a > b ? a : b)

struct Minion
{
	int a, b, c, d, e, f;
} A[2][10];

int check()
{
	int c[30] = {0}, mx = 0, i, j, cnt = 0;
	for (i = 0; i <= 1; i++)
	{
		for (j = 1; j <= 7; j++)
		{
			if (A[i][j].b <= 0) continue;
			cnt++;
			c[A[i][j].b + A[i][j].d] = 1;
			c[A[i][j].b + A[i][j].d + A[i][j].f] = 1;
			mx = max(mx, A[i][j].b + A[i][j].d + A[i][j].f);
		}
	}
	if (cnt <= 2) return 0;
	for (i = 1; i <= mx; i++)
		if (!c[i]) return 0;
	return 1;
}

int main()
{
	int t, i, j, suc, x, y;
	
	scanf("%d", &t);
	while (t--)
	{
		for (i = 0; i <= 1; i++)
			for (j = 1; j <= 7; j++) scanf("%d%d%d%d%d%d", &A[i][j].a, &A[i][j].b, &A[i][j].c, &A[i][j].d, &A[i][j].e, &A[i][j].f);
		suc = check();
		for (i = 0; !suc; i ^= 1)
		{
			x = y = 0;
			for (j = 1; j <= 7; j++)
			{
				if (A[i][j].b > 0 && (!x || A[i][j].a > A[i][x].a))
				{
					x = j;
				}
			}
			for (j = 1; j <= 7; j++)
			{
				if (A[i ^ 1][j].b > 0 && (!y || A[i ^ 1][j].c > A[i ^ 1][y].c || A[i ^ 1][j].c == A[i ^ 1][y].c && A[i ^ 1][j].b > A[i ^ 1][y].b))
				{
					y = j;
				}
			}
			if (!x || !y) break;
			if (A[i][x].d)
			{
				A[i][x].d = 0;
			}
			else
			{
				A[i][x].b -= A[i ^ 1][y].a;
			}
			if (A[i ^ 1][y].d)
			{
				A[i ^ 1][y].d = 0;
			}
			else
			{
				A[i ^ 1][y].b -= A[i][x].a;
			}
			if (A[i][x].b <= 0 && A[i][x].e)
			{
				A[i][x].a = A[i][x].e, A[i][x].b = A[i][x].f;
				A[i][x].c = A[i][x].d = A[i][x].e = A[i][x].f = 0;
			}
			if (A[i ^ 1][y].b <= 0 && A[i ^ 1][y].e)
			{
				A[i ^ 1][y].a = A[i ^ 1][y].e, A[i ^ 1][y].b = A[i ^ 1][y].f;
				A[i ^ 1][y].c = A[i ^ 1][y].d = A[i ^ 1][y].e = A[i ^ 1][y].f = 0;
			}
			suc |= check();
		}
		puts(suc ? "1" : "0");
	}

	return 0;
}
