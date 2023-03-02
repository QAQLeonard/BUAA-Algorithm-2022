#include <bits/stdc++.h>
#define maxn 55

using namespace std;

int t, n, m;
int a[maxn], b[maxn], c[maxn], d[maxn];
bool vis[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= m;i++) scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]), vis[i] = false;
		for(int i = 1;i <= n;i++){
			int cnt[2] = {0};
			for(int j = 1;j <= m;j++) if(!vis[j]){
				if(a[j] == i) cnt[b[j]]++, vis[j] = true;
				if(c[j] == i) cnt[d[j]]++, vis[j] = true;
			}
			printf("%d", cnt[0] > cnt[1]);
		}
		puts("");
	}
}
