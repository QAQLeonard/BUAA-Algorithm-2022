#include<cstdio>
#include<algorithm>
using namespace std;
int i,j,cnt = 0,n;
double w,v,k,res,add;
struct node {
	double w;
	double rate;
	inline bool operator < (const node& o)const {
		return o.rate < rate;
	}
} Node[10007];
int main() {

	scanf("%d %lf",&n,&k);

	for(int i = 0; i<n; i++) {
		scanf("%lf %lf",&v,&w);
		Node[i].w = w;
		Node[i].rate =  v/w;
	}
	sort(Node,Node+n);
	cnt = 0;
	res = 0.0;

	while(k>0.0 && cnt < n && Node[cnt].rate>0) {
		add = min(k , Node[cnt].w);
		res += add*Node[cnt++].rate;
		k-=add;
	}

	printf("%.3lf\n",res);

	return 0;
}
