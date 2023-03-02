#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int s;


int n, m;
vector<int> vec[N];
int vis[N], temp[N];

vector<int> topologicalorder(int n)
{
    vector<int> orders;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (temp[i] <= 0)
        {
            q.push(i);
            orders.push_back(i);
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < vec[u].size(); i++)
        {
            temp[vec[u][i]]--;
            if (temp[vec[u][i]] <= 0)
            {
                q.push(vec[u][i]);
                orders.push_back(vec[u][i]);
            }
        }
    }
    return orders;
}

int main()
{
    std::ios::sync_with_stdio(false); //有了这两句之后就不能使用printf，scanf
    std::cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {  
        memset(vec, 0, sizeof(vec));
        memset(vis, 0, sizeof(vis));
        memset(temp, 0, sizeof(temp));
        cin >> n >> m;
        for (int i = 0; i < m; i++) // adjacency list
        {
            int node;
            int u, v;
            cin >> u >> v;
            if (u != v)
            {
                node = v;
                vec[u].push_back(node);
                vis[v]++;
            }
        }
        memcpy(temp, vis, sizeof(vis));
        vector<int> path = topologicalorder(n);
        bool flag1 = false, flag2 = false;
        for (int i = 0; i < path.size() - 1; i++)
        {
            for (int j = 0; j < vec[path[i]].size(); j++)
            {
                if (vec[path[i]][j] == path[i + 1])
                {
                    flag1 = true;
                    break;
                }
            }
            if (!flag1)
            {
                flag2 = true;
                break;
            }
            else
            {
                flag1 = false;
            }
        }

        if (!flag2)
            cout << "yy" << endl;
        else
            cout << "nn" << endl;
    }
}
