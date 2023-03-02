#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    long long n, m, k;
    while (scanf("%lld%lld%lld", &n, &m, &k) != EOF)
    {
        long long ans = n;
        while (k--)
        {
            n += m;
            ans += n;
        }
        printf("%lld\n", ans);
    }

    return 0;
}