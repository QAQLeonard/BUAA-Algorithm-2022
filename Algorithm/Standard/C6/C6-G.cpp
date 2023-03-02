#include <bits/stdc++.h>
using namespace std;
int t;
long long a,b,n,m;

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a, &b);
		n=180*b-2*a;
		m=360*b;
		printf("%lld\n",m / __gcd(n,m) - 1);
	}
	return 0;
 } 
