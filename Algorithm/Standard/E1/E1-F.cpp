#include<bits/stdc++.h>
#define MIN(a,b) a<b?a:b
using namespace std;
vector<int>a[100005];
int b[100005];
bool path[100005];
char s[100010];
void dfs(int u) {
	if(a[u].empty()) {
		return;
	}
	for(int i=0; i<a[u].size(); i++) {
		b[a[u][i]]^=b[u];
		dfs(a[u][i]);
	}
}
int main() {
	int n,q;
	int x;
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d",&n);
		for(int i = 1; i <= n; i++) a[i].clear(), b[i] = 0;
		for(int i=2; i<=n; i++) {
			scanf("%d",&x);
			a[x].push_back(i);
		}
		scanf("%s",s);
		scanf("%d",&q);
		while(q--) {
			scanf("%d",&x);
			b[x]^=1;
		}
		dfs(1);
		for(int i=0; i<n; i++) {
			printf("%d",(s[i]-'0')^b[i+1]);
		}
		puts("");
	}
}
