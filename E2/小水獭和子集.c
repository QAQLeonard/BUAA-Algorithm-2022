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

int combine(int n, int num) //��n������ѡm�� �ж��������
{
    
    int m=(n+1)/2;
    int cnt=0;
    int i, j, t;
    int *a = (int *)malloc(sizeof(int) * m);
    for (i = 0; i < m; i++)
    {
        a[i] = i + 1; //��һ���
    }

    while (a[0] <= n - m + 1)
    {
        
        for (; a[m - 1] <= n; a[m - 1]++)
        { //ĩλ����������� ��� ֱ����λ
            printf("%d ",m);
            for (t = 0; t < m; t++)
            {
                printf("%d ", a[t]);
            }
            printf("\n");
            cnt++;
            if(cnt==num) return 0;
        }
        for (j = m - 2; j >= 0; j--)// m-2��һλ�ؽ�λ ������ܼ�����λ
        {           
            a[j]++; //һλ��λ
            if (a[j] <= j + n - m + 1)
                break; //��������λ
        }
        for (j++; j < m; j++)
        { //��λλ֮��Ӧ���ε���
            a[j] = a[j - 1] + 1;
        }
    }
    free(a);
    return 0;
}