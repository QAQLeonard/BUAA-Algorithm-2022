#include <bits/stdc++.h>
#define maxn 10086

using namespace std;

char s[18][maxn];
int len[18];
int nxt[maxn];

int cal(int x, int y){
	for(int i = 1;i < len[x];i++){
		int j = nxt[i - 1];
		while(j > 0 && s[x][i] != s[x][j]) j = nxt[j - 1];
		if(s[x][i] == s[x][j]) j++;
		nxt[i] = j;
	}
	int j = 0;
	for(int i = 0;i < len[y];i++){
		while(j > 0 && s[x][j] != s[y][i]) j = nxt[j - 1];
		if(s[x][j] == s[y][i]) j++;
		if(j == len[x]) return -1;
	}
	return j;
}

int t, n;
int a[18][18]; 
int f[1 << 18][18];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0;i < n;i++) scanf("%s", s[i]), len[i] = strlen(s[i]);
		vector<int> v;
		for(int i = 0;i < n;i++){
			bool tag = false;
			for(int j = 0;j < n;j++) if(i ^ j){
				a[j][i] = cal(i, j);
				if(a[j][i] == -1){
					if(len[i] < len[j] || i < j){
						tag = true;
						break;
					}
				}
			}
			if(tag) continue;
			v.push_back(i);
		}
		int m = v.size();
		for(int i = 0;i < (1 << m);i++) for(int j = 0;j < m;j++) f[i][j] = 1e9;
		for(int i = 0;i < m;i++) f[1 << i][i] = len[v[i]];
		for(int i = 0;i < (1 << m);i++) for(int j = 0;j < m;j++){
			for(int k = 0;k < m;k++) if(!(i & (1 << k))){
				f[i | (1 << k)][k] = min(f[i | (1 << k)][k], f[i][j] + len[v[k]] - a[v[j]][v[k]]);
			}
		}
		int ans = 1e9;
		for(int i = 0;i < m;i++) ans = min(ans, f[(1 << m) - 1][i]);
		printf("%d\n", ans);
	}
}
