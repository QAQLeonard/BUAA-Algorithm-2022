#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e6 + 5;

int n;
long long c, a[N], b[N], r;

void solve()
{
	scanf("%d%lld", &n, &c);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	for (int i = n; i > 1; i--)
	{
		b[i - 1] = a[i];
		a[i] -= b[i - 1];
		a[i - 1] -= c * b[i - 1];
	}
	r = a[1];
	for (int i = 1; i < n; i++)
		printf("%lld ", b[i]);
	printf("%lld\n", r);
}

int main()
{
	int T = 1;
	// scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}
