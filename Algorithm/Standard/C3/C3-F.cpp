#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
#include<assert.h>
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
int num[N];
int S(int x){
    int state = 0;
    for(; x; x /= 10)
        state |= 1 << (x % 10);
    return state;
}
int main(){

    int q = getint();

    while(q --) {
        int n = getint();
        assert(1 <= n && n <= 1000000);

        ll ans = 0;
        memset(num, 0, sizeof num);
        for(int i = 1; i <= n; i ++){
            int s = S(i);
            ans += num[s], num[s] ++; 
        }
        cout << ans << endl;
    }
}
