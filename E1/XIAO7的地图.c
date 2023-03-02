#include <stdio.h>
#include <stdbool.h>

typedef struct MAP
{
	int arr[2050][2050];
	int length;
	bool flag;
}map;

map m[10];

int get_length(int i)
{
    if(i>0)
    {
        m[i].length=2*get_length(i-1)+1;
        return m[i].length;
    }
    else if(i==0)
    {
        return 3;
    }
    else
    {
		printf("ERROR!!!");
		return 0;
	}
}

int main()
{
    /*for(int i=0;i<2048;i++)
    {
        for(int j=0;j<2048;j++)
        {
            if(m[0].arr[i][j]!=0) printf("error!");
        }
    }*/

    m[0].arr[0][0]=1;
    m[0].arr[0][1]=1;
    m[0].arr[0][2]=1;
    m[0].arr[1][0]=1;
    m[0].arr[2][0]=1;
    m[0].arr[2][1]=1;
    m[0].arr[2][2]=1;
    m[0].length=3;

    int n=0;
    scanf("%d",&n);

    get_length(n-1);

    for(int t=1;t<n;t++)
    {
        int temp=m[t-1].length;

        for(int i=0;i<temp;i++)
        {
            for(int j=0;j<temp;j++)
            {
                m[t].arr[i][j]=m[t-1].arr[i][j];
            }
        }

        for(int i=0;i<temp;i++)
        {
            for(int j=0;j<temp;j++)
            {
                m[t].arr[i+temp+1][j]=m[t-1].arr[i][j];

            }
        }

        for(int i=0;i<temp;i++)
        {
            for(int j=0;j<temp;j++)
            {
                m[t].arr[temp-j-1][i+temp+1]=m[t-1].arr[i][j];
            }
        }

        for(int i=0;i<temp;i++)
        {
            for(int j=0;j<temp;j++)
            {
                m[t].arr[temp+1+j][2*temp-i]=m[t-1].arr[i][j];
            }
        }

        m[t].arr[0][temp]=1;
        m[t].arr[2*temp][temp]=1;
        m[t].arr[temp][temp-1]=1;

    }

    int temp=m[n-1].length;
    
    for(int i=0;i<temp;i++)
    {
        for(int j=temp-1;j>=0;j--)
        {
            if(m[n-1].arr[i][j]==1)printf("*");
            else printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}
