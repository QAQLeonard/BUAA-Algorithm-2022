/*
字符串每次变化可以将第一位的字符移动到自身的末尾，如 abc 经过变化可以变为 bca。
有两个只包含小写字母的变化字符串 s 和 t，在不限制变化次数的情况下，这两个字符串是否会相同。
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str1, str2;
        cin >> str1 >> str2;
        vector<vector<int>> record(str1.length(), vector<int>(str2.length()));
        int maxLen = 0, maxEnd1 = 0, maxEnd2 = 0;
        for (int i = 0; i < static_cast<int>(str1.length()); ++i)
        {
            for (int j = 0; j < static_cast<int>(str2.length()); ++j)
            {
                if (str1[i] == str2[j])
                {
                    if (i == 0 || j == 0)
                    {
                        record[i][j] = 1;
                    }
                    else
                    {
                        record[i][j] = record[i - 1][j - 1] + 1;
                    }
                }
                else
                {
                    record[i][j] = 0;
                }

                if (record[i][j] > maxLen)
                {
                    maxLen = record[i][j];
                    maxEnd1 = i; // 若记录i,则最后获取LCS时是取str1的子串
                    maxEnd2 = j; // 若记录j,则最后获取LCS时是取str2的子串
                }
            }
        }
        //cout << str1.substr(maxEnd1 - maxLen + 1, maxLen) << endl;
        string newstr1 = str1.substr(maxEnd1 + 1) + str1.substr(0, maxEnd1 - maxLen + 1);
        string newstr2 = str2.substr(maxEnd2 + 1) + str2.substr(0, maxEnd2 - maxLen + 1);
        if (newstr1 == newstr2)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}