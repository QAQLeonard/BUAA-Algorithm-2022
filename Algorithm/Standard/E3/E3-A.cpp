#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue<long long, vector<long long>, greater<long long>> q;
long long n, i, tmp, a, b;
long long ans;
void init()
{
	ans = 0;
	while (!q.empty())
		q.pop();
}
int main()
{
	scanf("%lld", &n);
		init();
		for (i = 0; i < n; i++)
		{
			scanf("%lld", &tmp);
			q.push(tmp);
		}
		while (q.size() != 1)
		{
			a = q.top();
			q.pop();
			ans += 2*a;
			b = q.top();
			q.pop();
			ans += 2*b;
			q.push(a + b);
		}
		printf("%lld\n", ans);
	return 0;
}
