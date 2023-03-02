#include<bits/stdc++.h>
using namespace std;
const int maxn=20000,maxe=60000;
int n,m,cnt,s,t;
int head[maxn],dis[maxn],sum[maxn];
int inf = 0x3f3f3f3f;
bool vis[maxn];//标记是否在队列中
struct node {
	int to,next,w;
} e[maxe];

void add(int u,int v,int w) {
	e[cnt].to=v;
	e[cnt].next=head[u];
	e[cnt].w=w;
	head[u]=cnt++;
}

bool spfa(int u) {
	queue<int>q;
	memset(vis,0,sizeof(vis));//标记是否在队列中
	memset(sum,0,sizeof(sum));//统计入队的次数
	for(int i = 1 ; i <= n; i++)
		dis[i] = 1000000000;
	vis[u]=1;
	dis[u]=0;
	sum[u]++;
	q.push(u);
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		vis[x]=0;
		for(int i=head[x]; ~i; i=e[i].next) {
			int v=e[i].to;
			if(dis[v]>dis[x]+e[i].w) {	//判断条件
				dis[v]=dis[x]+e[i].w;
				if(!vis[v]) {
					if(++sum[v]>=n)
						return true;
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	return false;
}

void print() { //输出源点到其它节点的最短距离
	for(int i=1; i<=n; i++) {
		if(dis[i]<1000000000)
			cout<<dis[i]<<" ";
		else
			cout<<1000000000<<" ";
	}
	cout<<endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--) {
		cnt=0;
		cin>>n>>m;
		memset(head,-1,sizeof(head));
		int u,v,w;
		for(int i=1; i<=m; i++) {
			cin>>u>>v>>w;
			add(u,v,w);
		}
		bool flag = true;
		for(int j = n; j >= 1 ; j--){
			if(spfa(j)){
				cout<<"boo how"<<endl;
				flag = false;
				break;
			}
		}
		if(flag)
			print();
	}
	return 0;
}
