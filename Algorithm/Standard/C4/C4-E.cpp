#include<bits/stdc++.h>
#define maxn 10000002
using namespace std;
char s[maxn];
int fre[100],ans,t,i,sum,a,b,l;
priority_queue <int,vector<int>,greater<int> > q;
int main() {
	scanf("%s",s);
	l = strlen(s);
	for(i=0; i<l; i++) {
		fre[s[i]-'A']++;
	}
	for(i=0; i<100; i++) {
		if(fre[i]!=0) {
			q.push(fre[i]);
			sum++;
		}
	}
	if(sum==1) {
		printf("%d",l);
		return 0;
	}
	while(q.size()>1) {
		a = q.top();q.pop();
		b = q.top();q.pop();
		ans+=(a+b);q.push(a+b);
	}
	printf("%d",ans);
}
