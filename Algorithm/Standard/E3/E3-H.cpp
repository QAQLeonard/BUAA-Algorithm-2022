#include <bits/stdc++.h>
#define maxn 1086

using namespace std;

const int p = 998244353;

int t, n;
char s[maxn];
int f[maxn][1 << 10][2][2];

void add(int &x, int y){
	x += y;
	if(x >= p) x -= p;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		for(int i = 1;i <= n;i++) for(int j = 0;j < 1024;j++) for(int k = 0;k <= 1;k++) for(int l = 0;l <= 1;l++) f[i][j][k][l] = 0;
		f[0][0][1][0] = 1;
		for(int i = 1;i <= n;i++) for(int j = 0;j < 1024;j++) for(int k = 0;k <= 9;k++) for(int l = 0;l <= 1;l++){
			int jj = j | (1 << k), ll = l | (k > 0);
			if(!ll) jj = 0;
			add(f[i][jj][0][ll], f[i - 1][j][0][l]);
			if(k <= s[i] - '0') add(f[i][jj][k == s[i] - '0'][ll], f[i - 1][j][1][l]);
		}
		int ans = 0;
		for(int i = 1;i < 1024;i++) add(ans, (f[n][i][0][1] + f[n][i][1][1]) * (1ll * f[n][i][0][1] + f[n][i][1][1] + p - 1) % p * (p + 1 >> 1) % p);
		printf("%d\n" ,ans);
	}
}
