#include <iostream>
#include <vector>
#include <algorithm>
#include <queue> //头文件
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int time;
    cin >> time;
    int m, n;
    for (int t = 0; t < time; t++)
    {
        cin >> n >> m;
        int temp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; //小根堆
        priority_queue<pair<int, int>, vector<pair<int, int>>> p;                          //大根堆
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            q.push(make_pair(temp, i));
            p.push(make_pair(temp, i));
        }

        int ans = 0;
        while (!v.empty())
        {

            if (m <= v.front())
            {
                ans++;
                v.erase(v.begin());
            }
            else
            {
                if (v.size() == 1)
                {
                    ans++;
                    v.erase(v.begin());
                }
                else
                {

                    int i = v.size() - 1;
                    if (v[i] + v.front() <= m)
                    {
                        ans++;
                        v.erase(v.begin() + i);
                        v.erase(v.begin());
                    }
                    else
                    {
                        ans++;
                        v.erase(v.begin());
                    }
                }
            }
        }
        cout << ans << endl;
    }
}
