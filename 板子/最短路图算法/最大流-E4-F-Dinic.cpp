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
LL cnt,tot;
LL head[N],d[N],ans[N];
bool vis[N];
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

void adde(LL u,LL v,LL c) {
	add(u,v,c);
	add(v,u,0);
}

bool bfs(LL s,LL t) { //分层
	memset(d,0,sizeof(d));
	queue<LL>q;
	d[s]=1;
	q.push(s);
	while(!q.empty()) {
		LL u=q.front();
		q.pop();
		for(LL i=head[u]; ~i; i=E[i].next) {
			LL v=E[i].v;
			if(!d[v]&&E[i].cap>E[i].flow) {
				d[v]=d[u]+1;
				q.push(v);
				if(v==t)  return 1;
			}
		}
	}
	return 0;
}

LL dfs(LL u,LL flow,LL t) { //在分层的基础上dfs
	if(u==t) return flow;
	LL rest=flow;
	for(LL i=head[u]; ~i&&rest; i=E[i].next) {
		LL v=E[i].v;
		if(d[v]==d[u]+1&&E[i].cap>E[i].flow) {
			LL k=dfs(v,min(rest,E[i].cap-E[i].flow),t);
			if(!k) d[v]=0;
			E[i].flow+=k;
			E[i^1].flow-=k;
			rest-=k;
		}
	}
	return flow-rest;
}

LL Dinic(LL s,LL t) {
	LL maxflow=0;
	while(bfs(s,t)) {
		maxflow+=dfs(s,inf,t);
	}
	return maxflow;
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
		write(Dinic(s,t));
		putchar('\n');
	}

	return 0;
}
