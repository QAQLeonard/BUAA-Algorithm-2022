/*
 此车间有 n 条流水线，每条流水线有 m 个装配站，编号都为 1,2,…,m，每条流水线同样编号的装配站都执行相同的功能。拼装一个成品要按顺序经过 m 个装配站才能加工完成，
 经过第 i 条流水线的第 j 个装配站要花费 pi,j 的时间，从第 i 条流水线移动到第 j 条流水线要花费 ti,j 的时间，
 请问制造一个成品最少时间是多少，而且具体在流水线装配的过程是什么呢？

 第一行一个正整数 t（1≤t≤10），表示数据组数。

对于每组数据，第一行两个正整数 n,m（1≤n≤10，2≤m≤100），含义同题目描述。

接下来 n 行，每行 m 个正整数 pi,1,pi,2,…,pi,m（0≤pi,j≤100），表示经过第 i 条流水线的第 j 个装配站要花费的时间。

接下来 n 行，每行 n 个正整数 ti,1,ti,2,…,ti,n（0≤ti,j≤10），表示从第 i 条流水线移动到第 j 条流水线所花费的时间，保证 ti,i=0 对 1≤i≤n 成立。

对于每组数据，输出 m+1 行：

第一行一个非负整数，表示制造一个成品的最少时间。

接下来 m 行，第 i（1≤i≤m）行一个正整数表示第 i 个装配站所在的流水线编号。如果有多种可能的答案，你可以输出任意一种。
*/

#include <iostream>
#include <vector>
using namespace std;
#define INF 1e9

int main()
{
    int t, n, m, i, j;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<vector<int>> p(n + 1, vector<int>(m + 1, 0)); // p[i][j]:经过第i条线第j站所用的时间
        vector<vector<int>> t(n + 1, vector<int>(n + 1, 0)); // t[i][j]:第i条线转换到第j条线所用的时间
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= m; j++)
            {
                cin >> p[i][j];
            }
        }
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                cin >> t[i][j];
            }
        }

        vector<vector<int>> T(n + 1, vector<int>(m + 1, INF));  // T[i][j]:第i条线到第j站所用的最短时间
        vector<vector<int>> path(n + 1, vector<int>(m + 1, 0)); // path[i][j]:第i条线到第j站所用的最短时间的前一流水线
        int r = INF;

        for (int line = 1; line <= n; line++)
        {
            T[line][1] = p[line][1];
        }

        // 核心
        for (int station = 2; station <= m; station++)
        {
            for (int endLine = 1; endLine <= n; endLine++)
            {
                for (int startLine = 1; startLine <= n; startLine++)
                {
                    // T[endLine][station] = min(T[endLine][station], T[startLine][station - 1] + p[endLine][station] + t[startLine][endLine]);
                    if (T[endLine][station] > T[startLine][station - 1] + p[endLine][station] + t[startLine][endLine])
                    {
                        T[endLine][station] = T[startLine][station - 1] + p[endLine][station] + t[startLine][endLine];
                        path[endLine][station] = startLine;
                    }
                }
            }
        }
        int minline = 1;
        // 返回所求的最短距离
        for (int line = 1; line <= n; line++)
        {
            if (r > T[line][m])
            {
                r = T[line][m];
                minline = line;
            }
        }
        cout << r << endl;
        vector<int> ans;
        for (int i = m; i >= 1; i--)
        {
            ans.push_back(minline);
            minline = path[minline][i];
        }
        for(int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i] << endl;
        }
    }
}