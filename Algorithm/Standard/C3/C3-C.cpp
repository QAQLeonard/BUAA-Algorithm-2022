#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
using namespace std;
#define maxn 100005
typedef long long ll;
int m;
ll dp[3][maxn];
int line[3][maxn];
int work[3][maxn];
int to[3][3];
int l;
vector<pair<int, int>> v;

inline void init()
{
	for (int i = 1; i <= 2; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			dp[i][j] = LLONG_MAX;
		}
	}
}

inline ll buildDP()
{
	for (int i = 1; i <= 2; ++i)
	{
		dp[i][1] = work[i][1];
	}
	
	// 每一列 
	for (int j = 2; j <= m; ++j)
	{
		// 每一条流水线行数 
		for (int i = 1; i <= 2; ++i)
		{
			// 前一条流水线行数 
			for (int k = 1; k <= 2; ++k)
			{
				if (dp[i][j] > work[i][j] + dp[k][j - 1] + to[k][i])
				{
					dp[i][j] = work[i][j] + dp[k][j - 1] + to[k][i];
					line[i][j] = k;
				}
			}
		}
	}
	ll result = LLONG_MAX;
	for (int i = 1; i <= 2; ++i)
	{
		result = min(dp[i][m], result);
	}

	if (result == dp[1][m])
	{
		l = 1;
	}
	else
	{
		l = 2;
	}
	return result;
}

void searchDP()
{
	v.push_back(make_pair(0, 0));
	for (int j = m; j >= 1; j--)
	{
		v.push_back(make_pair(j, l));
		l = line[l][j];
	}
	for (int j = m; j >= 1; j--)
	{
		printf("Station%d, Line%d\n", v[j].first, v[j].second);
	}
}

int main()
{
	scanf("%d", &m);
	init();
	for (int i = 1; i <= 2; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			scanf("%d", &work[i][j]);
		}
	}
	for (int i = 1; i <= 2; ++i)
	{
		for (int j = 1; j <= 2; ++j)
		{
			scanf("%d", &to[i][j]);
		}
	}
	printf("%lld\n", buildDP());
	searchDP();
}
