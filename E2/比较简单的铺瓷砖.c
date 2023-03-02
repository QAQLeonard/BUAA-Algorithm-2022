#include <stdio.h>
#include <string.h>

#define a 998244353
#define maxn 1000005

long long arr[maxn];

long long sum[maxn];

int main()
{
    memset(arr,0,sizeof(arr));
    memset(sum,0,sizeof(sum));
    

    scanf("%d", &t);
    
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 9;
    arr[4] = 21;
    sum[1]=1;
    sum[2]=3;
    sum[3]=12;
    sum[4]=33;

    int max_n=4;

    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        if (n == 1)
            printf("1\n");
        else if (n == 2)
            printf("2\n");
        else if (n == 3)
            printf("9\n");
        else if (n == 4)
            printf("21\n");
        else
        {
            int k = max_n+1;

            if (arr[n] != 0)
            {
                printf("%d\n", arr[n] % a);
            }
            else
            {
                while (k <= n)
                {
                    arr[k] = (arr[k - 1] % a + arr[k - 2] % a + ((arr[k - 3] % a) * 4) % a + ((arr[k - 4] % a) * 2) % a + 2*(sum[k-3]%a)+2)%a;
                    sum[k]=sum[k-1]+arr[k];
                    sum[k]%=a;
                    k++;
                }
                max_n=n;
                printf("%lld\n", arr[n] % a);
            }
        }
    }
}
