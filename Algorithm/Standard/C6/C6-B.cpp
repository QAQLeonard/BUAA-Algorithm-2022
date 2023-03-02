#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int x[maxn], y[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d%d", &x[i], &y[i]);
		bool tag = false;
		for(int i = 3;i <= n;i++){
			if(1ll * (x[i] - x[1]) * (y[i] - y[2]) != 1ll * (x[i] - x[2]) * (y[i] - y[1])){
				tag = true;
				break;
			}
		}
		puts(tag ? "how?" : "boo how! boo how!");
	}
}
