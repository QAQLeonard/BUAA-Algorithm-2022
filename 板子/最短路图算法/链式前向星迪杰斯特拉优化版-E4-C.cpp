#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll read() {
	ll X=0,w=1; char c=getchar();
	while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
	while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
	return X*w;
}

const ll N=10000000+10,M=15000000+10;

ll n,m,s,t;
struct edge { ll v,w,nxt; } e[M];
ll head[N];
void addEdge(ll u,ll v,ll w) {
	static ll cnt=0;
	e[++cnt]=(edge){v,w,head[u]},head[u]=cnt;
}

priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> Q; 
ll dis[N];
void dijkstra(ll s) {
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0,Q.push(make_pair(0,s));
	while (!Q.empty()) {
		ll u=Q.top().second,d=Q.top().first; Q.pop();
		if (d!=dis[u]) continue;
		for (ll i=head[u];i;i=e[i].nxt) {
			ll v=e[i].v,w=e[i].w;
			if (dis[u]+w<dis[v]) dis[v]=dis[u]+w,Q.push(make_pair(dis[v],v));
		}
	}
}

int main() {
	n=read(),m=read(),s=read(),t=read();
	for (ll i=1;i<=m;++i) {
		ll u=read(),v=read(),w=read();
		addEdge(u,v,w);
		addEdge(v,u,w);
	}
	dijkstra(s);
	printf("%lld",dis[t]);
	return 0;
}
