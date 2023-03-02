#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
#include<ctime>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int N = 1000005;
const int inf = 0x3f3f3f3f;
int getint(){
    char c;bool flag=0;int num=0;
    while((c=getchar())<'0'||c>'9')if(c=='-')flag=1;
    while(c>='0'&&c<='9'){num=num*10+c-48;c=getchar();}
    return flag ? -num : num;
}
pi a[N];
int main(){
    int n = getint(), t = getint();
    for(int i = 1; i <= n; i ++)
        a[i].first = getint(), a[i].second = getint();
    sort(a + 1, a + n + 1);
    
    if(!t) {
        puts("0"); return 0;
    }
    
    int ed = 0, ans = 0;
    for(int i = 1; i <= n && ed < t;) {
        int lasted = ed + 1;
        for(; a[i].first <= lasted && i <= n; i ++)
            ed = max(ed, a[i].second);
        if(lasted == ed + 1) break ;
        ans ++;
    }
    if(ed < t)
        puts("(=> <=)");
    else cout << ans << endl;
}
