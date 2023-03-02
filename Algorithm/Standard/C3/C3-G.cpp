#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
char s[maxn];
char T[14] = "1145141919810";
int f[maxn][14];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		memset(f, -0x3f, sizeof(f));
		f[0][0] = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 0;j < 14;j++){
				if(j < 13) f[i][j + 1] = max(f[i][j + 1], f[i - 1][j] + (s[i] == T[j]));
				f[i][1] = max(f[i][1], f[i - 1][j] + (s[i] == T[0]));
			}
		}
		int ans = 0;
		for(int i = 0;i < 14;i++) ans = max(ans, f[n][i]);
		printf("%d\n", ans);
	}
}
