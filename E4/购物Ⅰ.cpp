#include <iostream>
#include <vector>
using namespace std;

// floyed
int main()
{
    long long int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long int>> a(n + 1, vector<long long int>(n + 1, INT64_MAX));
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        long long int z;
        cin >> x >> y >> z;
        a[x][y] = min(a[x][y], z);
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
    for (int m = 0; m < q; m++)
    {
        int x, y;
        cin >> x >> y;
        if (a[x][y] == INT64_MAX)
        {
            cout << "No So1ution" << endl;
        }
        else
        {
            cout << a[x][y] << endl;
        }
    }
    return 0;
}