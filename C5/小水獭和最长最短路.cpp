#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// floyed
int main()
{
    std::ios::sync_with_stdio(false); //有了这两句之后就不能使用printf，scanf
    std::cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, m;
        cin >> n >> m;
        vector<vector<long long int>> a(n + 1, vector<long long int>(n + 1, INT64_MAX));
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            long long int z;
            cin >> x >> y >> z;
            a[x][y] = min(a[x][y], z);
            a[y][x] = min(a[y][x], z);
        }

        for (int i = 1; i <= n; i++)
        {
            a[i][i] = 0;
        }

        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (a[i][k] != INT64_MAX && a[k][j] != INT64_MAX)
                    {
                        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
                    }
                }
            }
        }
        long long int MAX = INT64_MIN;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[i][j] != INT64_MAX)
                    MAX = max(MAX, a[i][j]);
            }
        }
        vector<pair<int, int>> ans;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[i][j] == MAX)
                {
                    ans.push_back(make_pair(i, j));
                }
            }
        }
        cout << MAX << " " << ans.size() << endl;
        sort(ans.begin(), ans.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             {
            if (a.first == b.first)
            {
                return a.second < b.second;
            }
            return a.first < b.first; });
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    }
    return 0;
}