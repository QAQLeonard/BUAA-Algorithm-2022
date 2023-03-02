#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N = 3005;
int getint() {
	char c;
	bool flag=0;
	int num=0;
	while((c=getchar())<'0'||c>'9')if(c=='-')flag=1;
	while(c>='0'&&c<='9') {
		num=num*10+c-48;
		c=getchar();
	}
	return flag ? -num : num;
}
bool mat[N][N], tep[N][N];
void setMat(int sx, int sy, int n) {
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < n; j ++)
			mat[sx + i][sy + j] = tep[1 + i][1 + j];
}
void dfs(int n, int m, int sx, int sy) {
	if(n == 1) {
		mat[sx][sy] = mat[sx][sy + 1] = mat[sx][sy + 2] = 1;
		mat[sx + 1][sy] = mat[sx + 1][sy] = 0, mat[sx + 1][sy + 2] = 1;
		mat[sx + 2][sy] = mat[sx + 2][sy + 1] = mat[sx + 2][sy + 2] = 1;
		return ;
	}

	dfs(n - 1, m >> 1, sx, sy);

	int sz = m >> 1;
	for(int i = 1; i <= sz; i ++)
		for(int j = 1; j <= sz; j ++) {
			tep[i][j] = mat[sx + i - 1][sy + j - 1];
			mat[sx + i - 1][sy + j - 1] = 0;
		}

	setMat(sx, sy + sz + 1, sz);
	setMat(sx + sz + 1, sy + sz + 1, sz);

	for(int i = 1; i <= m; i ++)
		mat[sx + sz][i] = mat[i][sy + sz] = 0;
	mat[sx][sy + sz] = mat[sx + m - 1][sy + sz] = mat[sx + sz][sy + sz + 1] = 1;

	for(int i = 1; i <= sz/2; i ++)
		for(int j = i; j < sz - i + 1; j ++) {
			int r = tep[i][j];
			tep[i][j] = tep[sz - j + 1][i];
			tep[sz - j + 1][i] = tep[sz - i + 1][sz - j + 1];
			tep[sz - i + 1][sz - j + 1] = tep[j][sz - i + 1];
			tep[j][sz - i + 1] = r;
		}

	setMat(sx, sy, sz);

	for(int i = 1; i <= sz/2; i ++)
		for(int j = 1; j <= sz; j ++)
			swap(tep[i][j], tep[sz - i + 1][j]);

	setMat(sx + sz + 1, sy, sz);
}
int main() {
	int n = getint(), m = 3;
	for(int i = 2; i <= n; i ++)
		m = m << 1 | 1;
	dfs(n, m, 1, 1);

	for(int i = 1; i <= m; i ++) {
		int j = m;
		for(; mat[i][j] == 0; j --);
		for(int k = 1; k <= j; k ++)
			putchar(mat[i][k] ? '*' : ' ');
		putchar(10);
	}
	return 0;
}
