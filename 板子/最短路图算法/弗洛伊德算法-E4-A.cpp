#include<bits/stdc++.h>
const int MN=500+5;
typedef long long ll;
using namespace std;
ll mat[MN][MN];
ll inf = 0x3f3f3f3f3f3f3f3f;
int m,n,p;
int main()
{	
	memset(mat,0x3f,sizeof mat);
	scanf("%d%d%d",&n,&m,&p);
	ll w;
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d%lld",&u,&v,&w);
		mat[u][v]=min(mat[u][v],w);	//ÖØ±ß 
	}
	for(int i=1;i<=n;i++){
		mat[i][i]=0;		// ×Ô»· 
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
		
	for(int i=0,u,v;i<p;i++){
		scanf("%d%d",&u,&v);
		if(mat[u][v]<inf) printf("%lld\n",mat[u][v]);
		else puts("No So1ution");
	}
	return 0;
}
