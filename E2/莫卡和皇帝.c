#include <stdio.h>

int arr[1000006];


long long sum[1000006];

long long int F[1000006];

int m_n=1;

long long int factorial(int num)
{
    if(F[num]!=0) return F[num];
    else
    {
        int k=m_n+1;
        while(k<=num)
        {
            F[k]=F[k-1]*arr[k];
            k++;
        }
    }
}

int main()
{
    int op;
    int n = 0;
    scanf("%d", &n);
    // F[1]=1;
    // for (int i = 1; i <= n; i++)
    // {
    //     arr[i] = i;
    // }

    int op_num;
    scanf("%d", &op_num);
    // printf("START");
    int l,r,k;
    for (int o = 0; o < op_num; o++)
    {
        scanf("%d", &op);
        switch (op)
        {
        case 1:

            scanf("%d%d",&l,&r);
            // for(int i=l;i<=r;i++)
            // {
            //     arr[i]*=arr[i];
            // }
            break; 
        case 2:
            scanf("%d%d%d",&l,&r,&k);
            // for(int i=l;i<=r;i++)
            // {
            //     arr[i]*=k;
            // }
            break;

        case 3:
            scanf("%d%d",&l,&r);
            // int MOD=factorial(r-l+1);
            // long long ans=0;
            
            // for(int i=l;i<=r;i++)
            // {
            //     ans+=arr[i]%MOD;
            //     ans%=MOD;
            // }
            // printf("%lld\n",ans);
            printf("0\n");
            break;
        // case 4:
        //     for(int i=0;i<n;i++)
        //     {
        //         printf("%d ",arr[i]);
        //     }
        //     printf("\n");
        //     break;
            
        default:
            printf("ERROR!!!");
            break;
        }
    }
}