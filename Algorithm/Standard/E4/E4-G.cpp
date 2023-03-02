#include <cstdio>
#include <string.h>
const int N = 105;
struct edge {
	int u, v;
	long long w;
};
edge e[N * N];
int cnt = 0;
long long dis[N][N][N];
int n, m, q, u, v, w, s, t, k;
void BF(int s) {
	for (int i = 0; i <= n - 1; i++) {
		dis[i][s][s] = 0ll;
	}
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= n; j++) {
			dis[i][s][j] = dis[i - 1][s][j];
		}
		for (int j = 1; j <= cnt; j++) {
			if (dis[i][s][e[j].v] > dis[i - 1][s][e[j].u] + e[j].w) {
				dis[i][s][e[j].v] = dis[i - 1][s][e[j].u] + e[j].w;
			}
			if (dis[i][s][e[j].u] > dis[i - 1][s][e[j].v] + e[j].w) {
				dis[i][s][e[j].u] = dis[i - 1][s][e[j].v] + e[j].w;
			}
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		e[++cnt].u = u;
		e[cnt].v = v;
		e[cnt].w = (long long)w;
	}
	for (int i = 0; i <= n - 1; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				dis[i][j][k] = 1ll << 60;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		BF(i);
	}
	for (int i = 1; i <= q; i++) {
		scanf("%d%d%d", &s, &t, &k);
		if (k >= n) {
			if (dis[n - 1][s][t] == 1ll << 60) {
				printf("-1\n");
			} else {
				printf("%lld\n", dis[n - 1][s][t]);
			}
		} else {
			if (dis[k][s][t] == 1ll << 60) {
				printf("-1\n");
			} else {
				printf("%lld\n", dis[k][s][t]);
			}
		}
	}
	return 0;
}
