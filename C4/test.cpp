#include <bits/stdc++.h>
#define maxn 1005

using namespace std;
int n, v;
int c[maxn];
int w[maxn];
long long int dp[int(1e5 + 5)];
int main()
{

    cin >> n >> v;

    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        cin >> c[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = v; j >= 0; j--)
        {
            if (j - c[i] >= 0)
                dp[j] = max(dp[j - c[i]] + w[i], dp[j]);
        }
    }
    cout << dp[v] << endl;
    return 0;
}
