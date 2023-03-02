#include <bits/stdc++.h>
#define mp make_pair
#define ms(a,b) memset(a,b,sizeof(a))
#define maxn 1000007
typedef long long LL;
using namespace std;

struct edge
{
	LL u,v;
	LL w;
};
struct edge edges[60000100];
LL i;
LL Father[1010000];
LL cnt;
long long res;
void initFather(LL vertexNum)
{
	LL i; 
	for(i=1;i<=vertexNum;++i)
	{
		Father[i]=i;
	}
}
LL getFather(LL x)
{
	return Father[x]==x?x:(Father[x]=getFather(Father[x]));
}
void kruskal(LL vertexNum,LL edgeNum)
{
	LL p,q;
	cnt=0,res=0;
	

	for(i=0;i<edgeNum;++i)
	{
		p=getFather(edges[i].u);
		q=getFather(edges[i].v);
		if(p!=q)
		{
			Father[p]=q;
			res+=edges[i].w;
			cnt++;
		}
		if(cnt==vertexNum-1)
		{
			break;
		}
	}

}
int cmp(const void*p1,const void*p2)
{
	struct edge *a=(struct edge*)p1;
	struct edge *b=(struct edge*)p2;
	return a->w-b->w;
}
int main()
{
	LL n,m;
	scanf("%lld%lld",&n,&m);
	initFather(n);
	LL i;
	for(i=0;i<m;++i)
		scanf("%lld %lld %lld",&edges[i].u,&edges[i].v,&edges[i].w);
	qsort(edges,m,sizeof(struct edge),cmp);
	kruskal(n,m);
	printf("%lld\n",res);
}
