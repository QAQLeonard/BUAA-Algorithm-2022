#include <bits/stdc++.h>
#define maxn 1005
using namespace std;

int ans[maxn], vis[maxn];
int n, k;

int play(int x) {
	if(!x) return 0;
	if(vis[x]) return ans[x];
	vis[x] = 1;
	int res = 0;
	for(int i = 1; i <= x; i *= k) {
		res |= !(play(x - i));
	}
	ans[x] = res;
	return  res;
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&k);
		if(k == 1 || n < k) {
			puts(n%2==0 ? "~B~" : "~A~");
		} else {
			for(int i = 0; i <= n; i++) 
			{
				vis[i] = 0, ans[i] = 0;
			}
			puts(play(n) ? "~A~" : "~B~");
		}
	}
	return 0;
}
