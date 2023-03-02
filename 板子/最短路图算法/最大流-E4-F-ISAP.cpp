#include <bits/stdc++.h>
#define mp make_pair
#define ms(a,b) memset(a,b,sizeof(a))
#define maxn 1000007
typedef long long LL;
using namespace std;
inline LL read() {
	LL X=0,w=1;
	char ch=0;
	while(ch<'0' || ch>'9') {
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') X=(X<<3)+(X<<1)+ch-'0',ch=getchar();
	return X*w;
}
inline void write(LL x) {
	if(x < 0)putchar('-'),x=-x;
	if (x > 9)write(x / 10);
	putchar(x % 10 + 48);
}
const LL inf=0x3f3f3f3f;
const LL N=2000005;
const LL M=2000005;
LL cnt;
LL head[N],pre[N],h[N],g[N];
struct Edge {
	LL v,next;
	LL cap,flow;
} E[M<<1]; //双边

void init() { //初始化
	memset(head,-1,sizeof(head));
	cnt=0;
}

void add(LL u,LL v,LL c) {
	E[cnt].v=v;
	E[cnt].cap=c;
	E[cnt].flow=0;
	E[cnt].next=head[u];
	head[u]=cnt++;
}

void set_h(LL t,LL n) { //标高
	queue<LL> q;
	memset(h,-1,sizeof(h));
	memset(g,0,sizeof(g));
	h[t]=0;
	q.push(t);
	while(!q.empty()) {
		LL u=q.front();
		q.pop();
		++g[h[u]];//高度为h[u]的节点个数
		for(LL i=head[u]; ~i; i=E[i].next) {
			LL v=E[i].v;
			if(h[v]==-1) {
				h[v]=h[u]+1;
				q.push(v);
			}
		}
	}
}

LL ISAP(LL s,LL t,LL n) {
	set_h(t,n);
	LL ans=0,u=s,d;
	while(h[s]<n) {
		LL i=head[u];
		if(u==s)
			d=inf;
		for(; ~i; i=E[i].next) {
			LL v=E[i].v;
			if(E[i].cap>E[i].flow&&h[u]==h[v]+1) {
				u=v;
				pre[v]=i;
				d=min(d,E[i].cap-E[i].flow);
				if(u==t) {
					while(u!=s) {
						LL j=pre[u];
						E[j].flow+=d;
						E[j^1].flow-=d;
						u=E[j^1].v;
					}
					ans+=d;
					d=inf;
				}
				break;
			}
		}
		if(i==-1) {
			if(--g[h[u]]==0)
				break;
			LL hmin=n-1;
			for(LL j=head[u]; ~j; j=E[j].next)
				if(E[j].cap>E[j].flow)
					hmin=min(hmin,h[E[j].v]);
			h[u]=hmin+1;
			++g[h[u]];
			if(u!=s)
				u=E[pre[u]^1].v;
		}
	}
	return ans;
}
LL n,m,s,t,T;
int main() {
	T = read();
	while(T--) {
		n = read(),m = read(),s = read(),t = read();
		init();
		for(LL i = 0; i<m; i++) {
			LL x = read();
			LL y = read();
			LL w = read();
			add(x,y,w);
			add(y,x,0);
		}
		write(ISAP(s,t,n));
		putchar('\n');
	}
	return 0;
}
