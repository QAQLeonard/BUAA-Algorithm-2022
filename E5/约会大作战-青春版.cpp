#include <bits/stdc++.h>
using namespace std;
/*第一行一个正整数 n（1≤n≤400），表示男生和女生的数量。

第二行 n 个非负整数 a1,a2,…,an（0≤ai≤109），表示男生的魅力值。

第三行 n 个非负整数 p1,p2,…,pn（0≤pi≤109），表示男生喜欢的女生魅力值最小值。

第四行 n 个非负整数 b1,b2,…,bn（0≤bi≤109），表示女生的魅力值。

第五行 n 个非负整数 q1,q2,…,qn（0≤qi≤109），表示女生喜欢的男生魅力值最小值。

男生与女生能约会当且仅当两人相互喜欢。那么最多有多少对情侣能约会成功呢？
*/

bool match(int boyIndex, int girlNumber, bool boyMatchGirlLine[405][405], bool used[], int girlMatchBoy[])
{
    for (int girlIndex = 1; girlIndex <= girlNumber; girlIndex++)
    {
        if (boyMatchGirlLine[boyIndex][girlIndex] && used[girlIndex] == false)
        {
            used[girlIndex] = true;
            if (girlMatchBoy[girlIndex] == -1 || match(girlMatchBoy[girlIndex], girlNumber, boyMatchGirlLine, used, girlMatchBoy))
            {
                girlMatchBoy[girlIndex] = boyIndex;
                return true;
            }
        }
    }
    return false;
}

bool boyMatchGirlLine[405][405];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<long long int, long long int>> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].second;
    }
    vector<pair<long long int, long long int>> b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i].first;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i].second;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i].first >= b[j].second && b[j].first >= a[i].second)
            {
                boyMatchGirlLine[i][j] = true;
            }
        }
    }
    // 最大适配数
    int sum = 0;

    // boyNumber为男生数量
    int boyNumber = n;
    // girlNumber为女生数量
    int girlNumber = n;

    //最终女生匹配男生的结果,girl[boyNumber]中的值为女生当前的对象索引 -1为无对象
    int girlMatchBoy[boyNumber+1];
    memset(girlMatchBoy, -1, sizeof(girlMatchBoy));

    //代表临时性的女生是否暂时有匹配男生
    bool used[boyNumber+1];

    //开始匹配
    for (int boyIndex = 1; boyIndex <= boyNumber; boyIndex++)
    {
        memset(used, false, sizeof(used));
        if (match(boyIndex, girlNumber, boyMatchGirlLine, used, girlMatchBoy))
        {
            sum += 1;
        }
    }
    cout<<sum<<endl;
}