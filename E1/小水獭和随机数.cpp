#include <bits/stdc++.h>
using namespace std;

unsigned seed;

int Rand()
{
	seed ^= seed << 13;
	seed ^= seed >> 7;
	seed ^= seed << 17;
	return seed & ((1 << 24) - 1);
}

int t, n;
int cnt[16777216];

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%u", &n, &seed);
		for(int i = 1;i <= n;i++)
		{ 
			cnt[Rand()]++;
		}
		unsigned ans = 0;
		int temp=0;
		for(int i=0;i<16777216;i++)
		{
			if(cnt[i]==0) continue;
			else
			{
				while(cnt[i]>0)
				{
					cnt[i]--;
					temp++;
					ans+=i^temp;
				}
			}
		}
		printf("%u\n", ans);
	}
}  
