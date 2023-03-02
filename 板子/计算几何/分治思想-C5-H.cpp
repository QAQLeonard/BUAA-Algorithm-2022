#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct Point{double x,y;}a[2000000],tmp[2000000];
int n,b[2000000];
const double inf=0x7fffffff;
double sqr(double x){return x*x;}
double dis(int l,int r){return sqr(a[l].x-a[r].x)+sqr(a[l].y-a[r].y);}
int cmp(const Point &a,const Point &b){return a.x==b.x?a.y<b.y:a.x<b.x;}
void merge(int l,int r)
{
	int mid=(l+r)>>1,i=l,j=mid+1;
	for(int k=l;k<=r;k++)
	{
		if(i<=mid&&(j>r||a[i].y<a[j].y))tmp[k]=a[i++];
		else tmp[k]=a[j++];
	}
	for(int i=l;i<=r;i++)a[i]=tmp[i];
}
double solve(int l,int r)
{
	if(l>=r)return inf;
	if(l+1==r){if(a[l].y>a[r].y)swap(a[l],a[r]);return dis(l,r);}
	int mid=(l+r)>>1,t=a[mid].x,cnt=0;
	double d=min(solve(l,mid),solve(mid+1,r));
	merge(l,r);
	for(int i=l;i<=r;i++)
		if(sqr(a[i].x-t)<d)
			b[++cnt]=i;
	for(int i=1;i<=cnt;i++)
		for(int j=i+1;j<=cnt&&sqr(a[b[j]].y-a[b[i]].y)<d;j++)
			d=min(d,dis(b[j],b[i]));
	return d;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lf%lf",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	printf("%.4lf",sqrt(solve(1,n)));
} 
