#include<stdio.h>
#include<math.h>

#define eps 1e-8

int main()
{
	int data_num=0;
	scanf("%d",&data_num);
	double a,b,k;
	//double logba;
	for(int i=0;i<data_num;i++)
	{
		scanf("%lf %lf %lf",&a,&b,&k);
		//logba=log10(a)/log10(b);
		//printf("%lf %lf",logba,k);
		double ans=pow(b,k);
		if(a-ans>eps) 
		{
			printf("n^{\\log_ba}\n");
		}
		else if(ans-a>eps)
		{
			printf("n^k\n");
		}
		else
		{
			printf("n^k\\log n\n");
		}
	}
	return 0;
}
