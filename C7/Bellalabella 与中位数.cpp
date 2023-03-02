#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
        }
        // 有n个数字，现在让你找出前2i-1项的中间值。（i=1,2,3,......(n+1)/2）
        priority_queue<int> maxHeap;                            // 大根堆
        priority_queue<int, vector<int>, greater<int>> minHeap; // 小根堆
        int mid;
        int step = 1;
        mid = v[1];
        cout << mid;
        step += 2;
        while (step <= n)
        {
            if (v[step - 1] < mid)
            {
                maxHeap.push(v[step - 1]);
            }
            else
            {
                minHeap.push(v[step - 1]);
            }

            if (v[step] < mid)
            {
                maxHeap.push(v[step]);
            }
            else
            {
                minHeap.push(v[step]);
            }

            if (maxHeap.size() > minHeap.size())
            {
                minHeap.push(mid);
                mid = maxHeap.top();
                maxHeap.pop();
            }
            else if (maxHeap.size() < minHeap.size())
            {
                maxHeap.push(mid);
                mid = minHeap.top();
                minHeap.pop();
            }
            cout << " " << mid;
            step += 2;
        }
        cout << endl;
    }
    return 0;
}