#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int t, n;
int a[maxn];
int sk[maxn], top;
int l[maxn], r[maxn];

void print(__int128 x){
	if(x < 10){
		printf("%d", (int)x);
		return;
	}
	print(x / 10);
	printf("%d", (int)(x % 10));
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		__int128 ans = 0;
		top = 0;
		for(int i = 1;i <= n;i++){
			while(top && a[sk[top]] <= a[i]) top--;
			if(top) l[i] = sk[top] + 1;
			else l[i] = 1;
			sk[++top] = i;
		}
		top = 0;
		for(int i = n;i;i--){
			while(top && a[sk[top]] < a[i]) top--;
			if(top) r[i] = sk[top] - 1;
			else r[i] = n;
			sk[++top] = i;
		}
		for(int i = 1;i <= n;i++) ans += (__int128)a[i] * (i - l[i] + 1) * (r[i] - i + 1);
		top = 0;
		for(int i = 1;i <= n;i++){
			while(top && a[sk[top]] >= a[i]) top--;
			if(top) l[i] = sk[top] + 1;
			else l[i] = 1;
			sk[++top] = i;
		}
		top = 0;
		for(int i = n;i;i--){
			while(top && a[sk[top]] > a[i]) top--;
			if(top) r[i] = sk[top] - 1;
			else r[i] = n;
			sk[++top] = i;
		}
		for(int i = 1;i <= n;i++) ans -= (__int128)a[i] * (i - l[i] + 1) * (r[i] - i + 1);
		print(ans);puts("");
	}
}
