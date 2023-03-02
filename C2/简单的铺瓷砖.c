#include <stdio.h>
#define a 998244353
#define maxn 1000005

long long ans[maxn];

int main()
{
    int t;
    scanf("%d", &t);
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 7;
    ans[4] = 15;
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        if (n == 1)
            printf("1\n");
        else if (n == 2)
            printf("2\n");
        else if (n == 3)
            printf("7\n");
        else if (n == 4)
            printf("15\n");
        else
        {
            int k = 5;
            if (ans[n] != 0)
            {
                printf("%d\n", ans[n] % a);
            }
            else
            {
                while (k <= n)
                {
                    ans[k] = ans[k - 1] % a + ans[k - 2] % a + ((ans[k - 3] % a) * 4) % a + ((ans[k - 4] % a) * 2) % a;
                    k++;
                }
                printf("%lld\n", ans[n] % a);
            }
        }
    }
}
