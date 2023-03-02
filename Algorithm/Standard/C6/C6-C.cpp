#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6;
const int P=31,D=1000173169;
int n,i,p[N],f[N];
char a[N];
int Hash(int l,int r) {
	return (ll)(f[r]-(ll)f[l-1]*p[r-l+1]%D+D)%D;
}
int main() {
	int t;
	scanf("%d",&t);
	assert(t>=1&&t<=10);
	while(t--) {
		scanf("%s",a+1);
		int n=strlen(a+1);
		assert(n>=1&&n<=1e6);
		for(p[0]=i=1; i<=n; i++) {
			p[i]=(ll)p[i-1]*P%D;
		}
		for(i=1; i<=n; i++) {
			f[i]=(ll)((ll)f[i-1]*P+a[i])%D;
		}
		for(i=1; i<=n; i++) {
			if(Hash(1,i)==Hash(n-i+1,n)) {
				printf("%d ",i);
			}
		}
		puts("");
	}

}


