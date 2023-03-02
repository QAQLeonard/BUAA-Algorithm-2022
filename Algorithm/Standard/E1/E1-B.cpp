#include<stdio.h>
#include<math.h>
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int k, z, index = 0;
		scanf("%d%d",&z,&k);
		if (k > 2)
			printf("0\n");
		else if( k == 1)
			printf("%d\n", z-1);
		else {
			for(long long i = 1; i < z; i++) {
				double j = sqrt(1ll * z * z - i * i);
				if(j == (int)j) {
					index++;
				}
			}
			printf("%d\n",index);
		}
	}
	return 0;
}
