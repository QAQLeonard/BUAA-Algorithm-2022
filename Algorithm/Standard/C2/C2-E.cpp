#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N = 90;
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
ll getll() {
	char c;
	bool flag=0;
	ll num=0;
	while((c=getchar())<'0'||c>'9')if(c=='-')flag=1;
	while(c>='0'&&c<='9') {
		num=num*10+c-48;
		c=getchar();
	}
	return flag ? -num : num;
}
ll f[N + 5];
ll getfa(ll x) {
	for(int i = N; i; i --)
		if(f[i] < x)
			return f[i - 1] - (x - f[i]) + 1;
	return 1;
}
int main() {
	f[1] = f[2] = 1;
	for(int i = 3; i <= N; i ++)
		f[i] = f[i - 1] + f[i - 2];

	int q = getint();
	while(q --) {
		ll x = getll(), y = getll();
		while(x != y)
			x > y ? x = getfa(x) : y = getfa(y);
		cout << x << endl;
	}

	return 0;
}
