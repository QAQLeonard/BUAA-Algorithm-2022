#include <stdio.h>

int max_m[11] = {0, 1, 2, 3, 6, 10, 20, 35, 70, 126, 252};

int combine(int n, int m);

int main()
{
    int time;
    scanf("%d", &time);
    int n = 0, m = 0;
    for (int t = 0; t < time; t++)
    {
        scanf("%d %d", &n, &m);
        if (m > max_m[n])
        {
            printf("-1\n");
            continue;
        }
        else
        {
            combine(n,m);
        }
    }

    return 0;
}

int combine(int n, int num) //从n个数中选m个 有多少种组合
{
    
    int m=(n+1)/2;
    int cnt=0;
    int i, j, t;
    int *a = (int *)malloc(sizeof(int) * m);
    for (i = 0; i < m; i++)
    {
        a[i] = i + 1; //第一组合
    }

    while (a[0] <= n - m + 1)
    {
        
        for (; a[m - 1] <= n; a[m - 1]++)
        { //末位递增产生组合 输出 直至进位
            printf("%d ",m);
            for (t = 0; t < m; t++)
            {
                printf("%d ", a[t]);
            }
            printf("\n");
            cnt++;
            if(cnt==num) return 0;
        }
        for (j = m - 2; j >= 0; j--)// m-2这一位必进位 往左可能继续进位
        {           
            a[j]++; //一位进位
            if (a[j] <= j + n - m + 1)
                break; //不继续进位
        }
        for (j++; j < m; j++)
        { //进位位之后应依次递增
            a[j] = a[j - 1] + 1;
        }
    }
    free(a);
    return 0;
}