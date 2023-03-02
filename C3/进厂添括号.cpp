#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<long long>> MATRIX_CHAIN_ORDER(vector<int> p)
{
    int n = p.size() - 1;
    vector<vector<long long>> m(n + 1, vector<long long>(n + 1, 0));
    vector<vector<long long>> s(n, vector<long long>(n + 1, 0));
    for (int l = 2; l <= n; l++)
    {
        int i;
        for (i = 1; i <= n - l + 1; i++)
        {
            int j = i + l - 1;
            m[i][j] = INT64_MAX;
            for (int k = i; k < j; k++)
            {
                long long q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    return m;
}

int main()
{
    int n = 0;
    cin >> n;
    vector<int> p;
    int temp;
    for(int i=0;i<=n;i++)
    {
        cin>>temp;
        p.push_back(temp);
    }
    cout<<MATRIX_CHAIN_ORDER(p)[1][n]<<endl;
}