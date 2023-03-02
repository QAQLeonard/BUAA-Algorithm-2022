#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int a[maxn], b[maxn], c[maxn];
int SA[maxn], rnk[maxn];
void build(char *s, int n, int m) {
	int *x = a, *y = b;
	s[n + 1] = 0;
	for (int i = 0; i <= n * 2 && i < maxn; i++) a[i] = b[i] = SA[i] = rnk[i] = 0;
	for (int i = 1; i <= m; i++) c[i] = 0;
	for (int i = 1; i <= n; i++) c[x[i] = s[i]]++;
	for (int i = 1; i <= m; i++) c[i] += c[i - 1];
	for (int i = n; i; i--) SA[c[x[i]]--] = i;
	for (int j = 1, p = 0; j <= n && p != n + 1; j <<= 1) {
		p = 0;
		for (int i = n - j + 1; i <= n; i++) y[++p] = i;
		for (int i = 1; i <= n; i++) if (SA[i] > j) y[++p] = SA[i] - j;
		for (int i = 1; i <= m; i++) c[i] = 0;
		for (int i = 1; i <= n; i++) c[x[y[i]]]++;
		for (int i = 1; i <= m; i++) c[i] += c[i - 1];
		for (int i = n; i; i--) SA[c[x[y[i]]]--] = y[i];
		std::swap(x, y); x[SA[1]] = 1; p = 2;
		for (int i = 2; i <= n; i++) x[SA[i]] = (y[SA[i]] == y[SA[i - 1]] && y[SA[i] + j] == y[SA[i - 1] + j]) ? p - 1 : p++;
		m = p;
	}
	for (int i = 1; i <= n; i++) rnk[SA[i]] = i;
}

int t, n;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s", s + 1);
		n = strlen(s + 1);
		build(s, n, 256);
		printf("%s\n", s + SA[1]);
	}
}
