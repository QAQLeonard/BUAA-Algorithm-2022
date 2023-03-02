#include <bits/stdc++.h>
#define maxn 1005

using namespace std;
int n, v;
int main()
{

    cin >> n >> v;
    vector<int> value(1005,0);
    vector<int> weight(1005,0);
    vector<long long int> dp(100005,0);
    for (int i = 1; i <= n; i++)
    {
        cin >> value[i];
        cin >> weight[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = v; j >= 0; j--)
        {
            if (j - weight[i] >= 0)
                dp[j] = max(dp[j - weight[i]] + value[i], dp[j]);
        }
    }
    cout << dp[v] << endl;
    return 0;
}
