#include<cstdio>
using namespace std;
typedef long long ll;
const int N = 500005;
int getint(){
    char c;bool flag=0;int num=0;
    while((c=getchar())<'0'||c>'9')if(c=='-')flag=1;
    while(c>='0'&&c<='9'){num=num*10+c-48;c=getchar();}
    return flag ? -num : num;
}
ll getll(){
    char c;bool flag=0;ll num=0;
    while((c=getchar())<'0'||c>'9')if(c=='-')flag=1;
    while(c>='0'&&c<='9'){num=num*10+c-48;c=getchar();}
    return flag ? -num : num;
}
int a[N], b[N], c[N], ans[N];
ll d[N], x[N];
int main(){

    int n = getint(), m = 0;
    for(int i = 1; i <= n; i ++)
        x[i] = getint();

    while(~scanf("%d", &a[++ m]))
        b[m] = getint(), c[m] = getint(), d[m] = getll();
    m --;

    ll j = -a[m --];

    for(int i = m; i; i --){
        ans[i] = j;
        ll A = 1ll * (x[j] ^ j) * (x[j] ^ j);
        ll B = 1ll * (x[j] ^ j) * x[j];
        ll C = 1ll * x[j] * x[j];
        ll t1 = a[i] * A + b[i] * B + c[i] * C + d[i];
        ll t2 = A + B + C + 1;

        j = -t1 / t2;

    }


    for(int i = 1; i <= m; i ++)
        printf("%d\n", ans[i]);
    return 0;
}
