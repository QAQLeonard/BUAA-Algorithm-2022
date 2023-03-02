#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

/**
 *第一行一个正整数 t（1≤t≤8），表示数据组数。

对于每组数据，第一行一个正整数 n（1≤n≤105），表示操作的数量。

接下来 n 行，每行为一个操作，格式如下：

1 x：向栈顶中插入元素 x（1≤x≤109）。

2：删除栈顶元素。

3：查询栈顶元素。


对于每次删除栈顶元素时，如果此时栈为空，输出一行 empty；否则无需输出。

对于每次查询栈顶元素时，如果此时栈为空，输出一行 empty；否则输出一行一个正整数，表示此时栈顶元素的值。

在所有操作结束后，将栈中的元素从小到大依次输出到一行中。
*/

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--)
    {
        stack<int> s;
        int n;
        cin >> n;
        int op, data;
        while (n--)
        {
            cin >> op;
            switch (op)
            {
            case 1:
                cin >> data;
                s.push(data);
                break;
            case 2:
                if (s.empty())
                {
                    cout << "empty" << endl;
                }
                else
                {
                    s.pop();
                }
                break;
            case 3:
                if (s.empty())
                {
                    cout << "empty" << endl;
                }
                else
                {
                    cout << s.top() << endl;
                }
                break;
            }
        }
        vector<int> ans;
        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout<<endl;
    }
    return 0;
}