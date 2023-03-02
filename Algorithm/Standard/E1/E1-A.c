#include <stdio.h>
#define maxn 200086

int t, n, m, k;
int a[maxn], A[maxn], b[maxn], B[maxn], c[maxn], C[maxn];

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
		scanf("%d", &m);
		for(int i = 1; i <= m; i++) scanf("%d", &b[i]);
		for(int i = 1; i <= m; i++) scanf("%d", &B[i]);
		int posa = 1, posb = 1;
		k = 0;
		while(posa <= n || posb <= m) {
			if(posa > n) c[++k] = b[posb], C[k] = B[posb], posb++;
			else if(posb > m) c[++k] = a[posa], C[k] = A[posa], posa++;
			else if(A[posa] == B[posb]) c[++k] = a[posa] + b[posb], C[k] = A[posa], posa++, posb++;
			else if(A[posa] < B[posb]) c[++k] = a[posa], C[k] = A[posa], posa++;
			else c[++k] = b[posb], C[k] = B[posb], posb++;
		}
		printf("%d\n", k);
		for(int i = 1; i <= k; i++) printf("%d ", c[i]);
		puts("");
		for(int i = 1; i <= k; i++) printf("%d ", C[i]);
		puts("");
	}
}
