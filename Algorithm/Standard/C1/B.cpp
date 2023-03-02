#include<stdio.h>
#define M 10007
long long a[1000001],b[1000001];
long long n,m,x,y,i,t,c;
long long Horner(long long *a,long long n,long long x) {
	if(n<1)
		return a[0] % M;
	else
		return (a[0] % M + (Horner(a+1,n-1,x) * x) % M) % M;
}

int main() {
	scanf("%lld",&n);
	for(i=0; i<=n; i++) {
		scanf("%lld",&a[i]);
	}
	scanf("%lld",&m);
	for(i=0; i<=m; i++) {
		scanf("%lld",&b[i]);
	}
	scanf("%lld",&c);
	while(c--)
	{
		scanf("%lld %lld",&x,&y);
		printf("%lld\n",( (Horner(a,n,x) % M) * (Horner(b,m,y) % M) ) % M );
	}
	return 0;
}

