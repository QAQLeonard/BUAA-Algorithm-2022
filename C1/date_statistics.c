#include <stdio.h>
#include <stdbool.h>

int date1;
int date2;

typedef struct Date
{
    int year;
    int month;
    int day;
} date;

int tmparr[10];

int ans=0;

void inttostr(int dd)
{
    for (int i = 7; i >= 0; i--)
    {
        tmparr[i] = dd % 10;
        dd /= 10;
    }
}

bool judge(int year, int month, int day)
{
    if (1 <= month && month <= 12)
    {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            if (day >= 1 && day <= 31)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            if (day >= 1 && day <= 30)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0)
        {
            if (day >= 1 && day <= 29)
            {
                return true;
            }
        }
        else if (day >= 1 && day <= 28)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
    return 0;
}

int main()
{
    scanf("%d",&date1);
    //printf("%dcnmd",date1);
    scanf("%d",&date2);
    //printf("%dcnmd",date2);
    for (int i = date1; i <= date2; i++)
    {
        if (((i % 10000) / 100 > 12) || ((i % 10000) / 100 < 1))
        {
            continue;
        }
        else if (i % 100 > 31)
        {
            continue;
        }
        if (!judge(i / 10000, (i % 10000) / 100, i % 100))
        {
            continue;
        }

        inttostr(i);

        int flag = -1;//flag=0=increase,flag=1=decrease
        int t = -1;
        for(int i=0;i<7;i++)
        {
            if (tmparr[i+1]>tmparr[i])
            {
                if(flag==0) continue;
                else
                {
                    flag=0;
                    t++;
                }
            }
            else if(tmparr[i+1]<tmparr[i])
            {
                if(flag==1) continue;
                else
                {
                    flag=1;
                    t++;
                }
            }
        }
        if(t<=1)
        {
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
