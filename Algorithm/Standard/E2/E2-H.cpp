#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<vector>
typedef long long int LL;
typedef unsigned long long ULL;
const int INF=0x3f3f3f3f;
const LL INFLL=0x3f3f3f3f3f3f3f3fll;
LL getint(){
    LL ret=0;bool f=0;char c;
    while((c=getchar())<'0'||c>'9')if(c=='-')f^=1;
    while(c>='0'&&c<='9'){ret=ret*10+c-'0';c=getchar();}
    return f?-ret:ret;
}
using namespace std;
const int MAXN=100;
bool xa[MAXN+10],xb[MAXN+10],ans[MAXN+10];
void update(LL a,bool x[MAXN+10]){
    if(a>=0){
        memset(x,0,(MAXN+10)*(sizeof(bool)));
        for(int i=0;a;++i,a>>=1)
            x[i]=a&1;
    }
    else{
        memset(x,1,(MAXN+10)*(sizeof(bool)));
        for(int i=0;~a;++i,a>>=1)
            x[i]=a&1;
    }
}
int main(){
    int T=getint();
    while(T--){
        LL a=getint(),b=getint();
        if(a<0&&b<0){
            printf("I would like to see xf wear a skirt every day !\n");
            continue;
        }
        memset(ans,0,sizeof ans);
        update(a,xa);update(b,xb);
        bool c=0;
        for(int i=0;i<70;++i){
            ans[i]=c^xa[i]^xb[i];
            c=((ans[i]^xa[i])+(ans[i]^xb[i])+c)>1;
        }
        LL ret;
        if(ans[65]){
            ret=-1;
            for(int i=0;i<70;++i)if(!ans[i])
                ret-=(1ll<<i);
        }
        else{
            ret=0;
            for(int i=0;i<70;++i)if(ans[i])
                ret+=(1ll<<i);
        }
        cout<<ret<<'\n';
    }
    return 0;
}
