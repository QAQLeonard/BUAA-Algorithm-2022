#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 10000006
using namespace std;
int n,m,s,t;
int dis[maxn];
int ans[maxn];
struct Edge{
    int t,nxt,w;
}edge[maxn*4];
int book[maxn];
int head[maxn],tot=0;
priority_queue< pair<int,int> > hep;
void add(int st,int to,int we){
    edge[tot].t=to;
    edge[tot].nxt=head[st];
    edge[tot].w=we;
    head[st]=tot;
    tot++;
}
void init(){
    scanf("%d %d %d %d",&n,&m,&s,&t);
    memset(book,0,sizeof(book));
    memset(head,-1,sizeof(head));
    memset(dis,0x3f,sizeof(dis));
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        add(a,b,1);
        add(b,a,1);
    }
    dis[s]=0;
    ans[s]=1;
    return;
}
void dij(){
    hep.push(make_pair(0-dis[s],s));
    while(!hep.empty()){
        int np=hep.top().second;hep.pop();
        if(book[np]) continue;
        book[np]=1;
        for(int i=head[np];i!=-1;i=edge[i].nxt){
            int w=edge[i].w;
            int t=edge[i].t;
            if(dis[t]>dis[np]+w){
                dis[t]=dis[np]+w;
                ans[t]=ans[np];
                hep.push(make_pair(0-dis[t],t));
            }
            else if(dis[t]==dis[np]+w){
            	ans[t]+=ans[np];
            	ans[t]%=998244353;
            }
        }
    }
        printf("%d\n",ans[t]);
    return;
}
int main(){
    init();
    dij();
    return 0;
} 
