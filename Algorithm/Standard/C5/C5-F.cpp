#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll read() {
	ll X=0,w=1; char c=getchar();
	while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
	while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
	return X*w;
}

const ll N=1000000+10,M=5000000+10;

ll n,m,k,t,ans = LLONG_MAX;
struct edge { ll v,w,nxt; } e[M];
ll head[N];
void addEdge(ll u,ll v,ll w) {
	static ll cnt=0;
	e[++cnt]=(edge){v,w,head[u]},head[u]=cnt;
}

priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> Q; 
ll dis[N];
ll dis2[N];
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
void dijkstra2(ll s) {
	memset(dis2,0x3f,sizeof(dis2));
	dis2[s]=0,Q.push(make_pair(0,s));
	while (!Q.empty()) {
		ll u=Q.top().second,d=Q.top().first; Q.pop();
		if (d!=dis2[u]) continue;
		for (ll i=head[u];i;i=e[i].nxt) {
			ll v=e[i].v,w=e[i].w;
			if (dis2[u]+w<dis2[v]) dis2[v]=dis2[u]+w,Q.push(make_pair(dis2[v],v));
		}
	}
}
int main() {
	n=read(),m=read(),k=read();
	for (ll i=1;i<=m;++i) {
		ll u=read(),v=read(),w=read();
		addEdge(u,v,w);
		addEdge(v,u,w);
	}
	dijkstra(1);
	dijkstra2(n);
	for (ll i=0;i<k;++i) {
		int t = read();
		ans = min(ans,dis[t] + dis2[t]);	
	}
	printf("%lld",ans);
	return 0;
}
