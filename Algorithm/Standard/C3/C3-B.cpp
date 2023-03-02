#include<bits/stdc++.h>
#define maxn 310
#define INF LLONG_MAX
typedef long long LL;
using namespace std;
LL m[maxn][maxn],s[maxn][maxn];
LL a[maxn],n;
void Matrixchain() {
	for(LL l=2; l<=n; l++)
		for(LL i=1; i<=n-l+1; i++) {
			LL j = i+l-1;
			m[i][j] = INF;
			for(LL k = i; k<j; k++) {
				LL tmp = m[i][k] + m[k+1][j] + a[i-1] * a[k] * a[j];
				if(tmp<m[i][j]) 	m[i][j] = tmp,s[i][j] = k;
			}
		}
}
int main() {
	scanf("%lld",&n);
	for(LL i=0; i<=n; i++)
		scanf("%lld",a+i);
	for(LL i=0; i<=n; i++)
		m[i][i] = 0;
	Matrixchain();
	printf("%lld\n", m[1][n]);
}
