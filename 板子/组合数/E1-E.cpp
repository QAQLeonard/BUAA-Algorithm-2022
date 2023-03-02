#include <bits/stdc++.h>

using namespace std;

int t, n, m;

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		m = min(m, n - m);
		long long x = 1;
		for(int i = 1; i <= m && x <= 1e9; i++) x *= n - i + 1, x /= i;
		printf("%d\n", x <= 1e9 ? x : -1);
	}
}
