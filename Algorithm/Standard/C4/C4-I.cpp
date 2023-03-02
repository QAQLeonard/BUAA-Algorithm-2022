#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n,i,x;
		long long Ans=0;
		scanf("%d",&n);
		scanf("%d",&x);
		for (i=2;i<=n;i++){
			int y;
			scanf("%d",&y);
			if (i&1){
				int t=max(y-x+1,0);
				y-=t;
				Ans+=t;
			}else{
				int t=max(x+1-y,0);
				y+=t;
				Ans+=t;
			}
			x=y;
		}
		printf("%lld\n",Ans);
	} 
	return 0;
}
