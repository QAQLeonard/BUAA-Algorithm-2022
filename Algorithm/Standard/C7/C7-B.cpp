#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
#include<ctime>
#include<map>
#include<assert.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const int N = 100005;
const ll inf = 1ll << 60;
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
pi a[N];
ll t[N];
int main() {

	int n;
	int tt;
	scanf("%d", &tt);
	while(tt--) {
		scanf("%d", &n);
		assert(n <= 1e5);
		for(int i = 1; i <= n; i ++) {
			a[i].second = getint();
			a[i].first = getint();
		}
		sort(a + 1, a + n + 1);

		int T = getint();
		for(int i = 1; i <= T; i ++) {
			t[i] = getint();
		}
		sort(t + 1, t + T + 1), t[T + 1] = inf;


		ll ans = 0, sum = 0;
		for(int i = 1, j = 1; i <= n; ) {
			if(sum + a[i].second <= t[j])  {
				ans += 1ll * j * a[i].first * a[i].second;
				sum += a[i].second, i ++;
			} else {
				ll m = t[j] - sum;
				a[i].second -= m;
				ans += 1ll * j * a[i].first * m;
				sum += m, j ++;
			}
		}

		cout << ans << endl;
	}

	return 0;
}
