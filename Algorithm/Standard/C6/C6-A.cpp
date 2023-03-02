#include<bits/stdc++.h>
using namespace std;
const int N = 2e6;
char s[N],t[N];
int a[N];
int nxt[N];
void kmp(int n,char *a,int m,char *b) {
	int i,j;
	for(nxt[0]=j=-1,i=1; i<n; nxt[i++]=j) {
		while(~j&&a[j+1]!=a[i])j=nxt[j];
		if(a[j+1]==a[i])j++;
	}
	for(j=-1,i=0; i<m; i++) {
		while(~j&&a[j+1]!=b[i])j=nxt[j];
		if(a[j+1]==b[i])j++;
		if(j==n-1)printf("%d ",i-n+1),j=nxt[j];
	}
}
int main() {
	scanf("%s",s);
	scanf("%s",t);
	int len1=strlen(t),len2=strlen(s);
	assert(len1>=1&&len1<=1e6);
	assert(len2>=1&&len2<=1e6);
	kmp(len1,t,len2,s);
}

