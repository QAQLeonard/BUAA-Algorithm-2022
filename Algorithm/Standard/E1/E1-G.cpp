#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
const int N = 55;
const int inf = 0x3f3f3f3f;
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
int A[N], B[N];
int match(int x, ll target) {
	int n = 0, m = 0, i, j;
	while(x)
		A[++ n] = x % 10, x /= 10;
	while(target)
		B[++ m] = target % 10, target /= 10;

	for(i = m, j = n; i && j; i --, j --) {
		for(; j && B[i] != A[j]; j --);
		if(j <= 0) break ;
	}

	int delete_num = n - (m - i);
	int add_num = i;

	return delete_num + add_num;
}
int main() {
	int T = getint();
	while(T --) {
		int n = getint(), ans = inf;
		for(int i = 0; i <= 60; i ++)
			ans = min(ans, match(n, 1ll << i));
		cout << ans << endl;
	}
	return 0;
}
