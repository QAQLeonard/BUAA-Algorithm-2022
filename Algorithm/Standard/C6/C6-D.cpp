#include<bits/stdc++.h>
#define inf 0x7fffffff
#define RG register int
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const long double eps = 1e-11;
//using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,w,h;
char ch[110005],pat[220005];
int pos,r[220005],ans;
int main(){
	int i,j,u,v;
	int t = read();
	while(t--){
		scanf("%s",ch+1);
		n=strlen(ch+1);
		pat[0]='@';
		ans = 0;
		for(int i = 0; i <= 2 * n + 2; i++) r[i] = 0;
		for(i=1;i<=n;i++) pat[2*i-1]=ch[i],pat[2*i]='@';
		pos=0,r[0]=0;
		for(i=1;i<=2*n;i++){
			if(i<=pos+r[pos]) r[i]=min(pos+r[pos]-i,r[pos*2-i]);
			while(i>r[i]&&pat[i+r[i]+1]==pat[i-r[i]-1]) r[i]++;
			if(i+r[i]>pos+r[pos]) pos=i;
			ans=max(ans,r[i]);
		}
		printf("%d\n", ans);
	}
    return 0;
}
