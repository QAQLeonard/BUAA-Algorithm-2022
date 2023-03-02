#include <iostream>
#include <vector>
using namespace std;

vector<int> arr(10000006, 0);
vector<long long int> sum;
vector<long long int> F(10000006, 0);

int m_n = 1;

long long int factorial(int num)
{
    if (F[num] != 0)
        return F[num];
    else
    {
        int k = m_n + 1;
        while (k <= num)
        {
            F[k] = F[k - 1] * arr[k];
            k++;
        }
    }
}

int main()
{
    int op;
    int n = 0;
    cin >> n;
    // F[1]=1;
    // for (int i = 1; i <= n; i++)
    // {
    //     arr[i] = i;
    // }

    int op_num;
    cin >> op_num;
    // printf("START");
    int l, r, k;
    for (int o = 0; o < op_num; o++)
    {
        cin >> op;
        switch (op)
        {
        case 1:

            cin >> l >> r;
            // for(int i=l;i<=r;i++)
            // {
            //     arr[i]*=arr[i];
            // }
            break;
        case 2:
            cin >> l >> r >> k;
            // for(int i=l;i<=r;i++)
            // {
            //     arr[i]*=k;
            // }
            break;

        case 3:
            cin >> l >> r;
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