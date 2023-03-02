#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

struct node{
    ll x, y;
    int f, id;
    void getf(){
        if(x >= 0 && y > 0) f = 1;
        else if(x < 0 && y >= 0) f = 2;
        else if(x <= 0 && y < 0) f = 3;
        else f = 4;
    }
    bool operator < (const node & a)const{return f < a.f || (f == a.f && x * a.y > y * a.x) || (f == a.f && x * a.y == y * a.x && id < a.id);}
}a[maxn];

const int p = 998244353;

int t, n;
int x[maxn], y[maxn];
int pw[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		pw[0] = 1;for(int i = 1;i <= n;i++) pw[i] = pw[i - 1] * 2 % p;
		for(int i = 1;i <= n;i++) scanf("%lld%lld", &a[i].x, &a[i].y), a[i].getf(), a[i].id = i;
		sort(a + 1, a + n + 1);
		for(int i = n + 1;i <= n * 2;i++) a[i] = a[i - n];
		int x = 1, ans = 0;
		for(int i = 1;i <= n;i++){
			while(x + 1 < i + n && (a[x + 1].x * a[i].y - a[i].x * a[x + 1].y == 0 && a[x + 1].f == a[i].f
	                || a[x + 1].x * a[i].y - a[i].x * a[x + 1].y < 0)){
				x++;
			}
			ans = (ans + pw[x - i]) % p;
		}
		printf("%d\n", ans);
	}
}
