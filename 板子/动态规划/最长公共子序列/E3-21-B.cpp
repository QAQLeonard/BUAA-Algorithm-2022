#include <iostream>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;
char str1[1005];
char str2[1005];
int dp[1005][1005], len1, len2;
void lcs()
{
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
}
void printlcs()
{
    char c[1005];
    memset(c, 0, sizeof(c));
    int i = len1;
    int j = len2;
    int z = 0;
    while (i != 0 && j != 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            c[z++] = str1[--i];
            j--;
        }
        else if (dp[i - 1][j] < dp[i][j - 1])
        {
            j--;
        }
        else if (dp[i][j - 1] <= dp[i - 1][j])
        {
            i--;
        }
    }
    for (i = z - 1; i >= 0; i--)
    {
        printf("%c", c[i]);
    }
    printf("\n");
}
int main()
{
    memset(dp, 0, sizeof(dp));
    cin >> str1;
    cin >> str2;
    // cout<<str1<<endl;
    // cout<<str2<<endl;
    len1 = strlen(str1);
    len2 = strlen(str2);
    lcs();
    printlcs();
    system("pause");
    return 0;
}