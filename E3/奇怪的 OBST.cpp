#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long int OPTIMAL_BST(vector<int> p, vector<int> q, int n)
{
    vector<vector<long long int>> e(n + 2, vector<long long int>(n + 1, 0));
    vector<vector<long long int>> w(n + 2, vector<long long int>(n + 1, 0));
    vector<vector<long long int>> root(n + 1, vector<long long int>(n + 1, 0));
    for (int i = 1; i <= n + 1; i++)
    {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }
    for (int l = 1; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            int j = i + l - 1;
            e[i][j] = INT64_MAX;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            for (int r = i; r <= j; r++)
            {
                int t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (t < e[i][j])
                {
                    e[i][j] = t;
                    root[i][j] = r;
                }
            }
        }
    }
    return e[1][n];
}

int main()
{
    int num;
    cin >> num;
    vector<int> p;
    vector<int> q(num + 1, 0);
    p.push_back(0);
    int temp;
    int sum = 0;
    for (int i = 0; i < num; i++)
    {
        cin >> temp;
        sum += temp;
        p.push_back(temp);
    }
    cout<<OPTIMAL_BST(p,q,num)<<endl;
}