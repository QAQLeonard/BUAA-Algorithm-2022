#include <iostream>
#include <vector>
#include <string>
using namespace std;

//经典的公共子序列问题，动归！

string longestCommonSubsequence(string text1, string text2)
{
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    vector<vector<int>> recoder(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++)
    {
        char c1 = text1.at(i - 1);
        for (int j = 1; j <= n; j++)
        {
            char c2 = text2.at(j - 1);
            if (c1 == c2)
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                recoder[i][j] = 0;
            }
            else
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                    recoder[i][j] = 1;
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                    recoder[i][j] = 2;
                }
            }
        }
    }
    string rans = "";
    while (m >= 1 && n >= 1)
    {
        switch (recoder[m][n])
        {
        case 0:
            rans.push_back(text1.at(m - 1));
            m--;
            n--;
            break;
        case 1:
            m--;
            break;
        case 2:
            n--;
            break;
        }
    }
    string ans(rans.rbegin(),rans.rend());
    return ans;
}

int main()
{
    string s1, s2;
    cin >> s1;
    cin >> s2;
    cout << longestCommonSubsequence(s1, s2) << endl;
}