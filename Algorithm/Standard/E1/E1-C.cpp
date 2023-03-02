#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, k, n;

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &k, &n);
		vector<int> v(k * n);
		for(int i = 0; i < k * n; i++) scanf("%d", &v[i]);
		sort(v.begin(), v.end());
		for(auto x : v) printf("%d ", x);
		puts("");
	}
}
